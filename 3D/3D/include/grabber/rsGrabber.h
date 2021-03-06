#ifndef RS_GRABBER
#define RS_GRABBER

#include "grabber/grabber.h"
#include "grabber/rsgrabber/real_sense_grabber.h"

#include<pcl/io/ply_io.h>

template <typename PointT>
class RSGrabber : Grabber<PointT>
{
public:
	typedef pcl::PointCloud<PointT> PointCloudT;

	RSGrabber(GrabberNotify* grabberNotify, std::string deviceId = "") : Grabber(grabberNotify)
	{
		_grabber = new pcl::RealSenseGrabber(deviceId);
		_function = boost::bind(&RSGrabber::CloudCallback, this, _1);
	}

	~RSGrabber()
	{
		_connection.disconnect();
	}

	void StartGrabber()
	{
		_connection = _grabber->registerCallback(_function);
		_grabber->start();
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloud()
	{
		return _cloud;
	}

	void StopGrabber()
	{
		_grabber->stop();
	}

	boost::mutex& GetMutex()
	{
		return _mutex;
	}

private:
	void CloudCallback(boost::shared_ptr<const pcl::PointCloud<PointT>> cloud)
	{
		boost::mutex::scoped_lock lock(_mutex);
		boost::shared_ptr<pcl::PointCloud<PointT>> cloudCpy = boost::const_pointer_cast<pcl::PointCloud<PointT>>(cloud);
		_cloud.reset(new pcl::PointCloud<PointT>(*cloudCpy));
		_grabberNotify->NotifyNewCloudArrived();
		//_connection.disconnect();
	}

	mutable boost::mutex _mutex;
	boost::function<void(const boost::shared_ptr<const pcl::PointCloud<PointT>>&)> _function;
	boost::signals2::connection _connection;
	pcl::RealSenseGrabber* _grabber;
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif