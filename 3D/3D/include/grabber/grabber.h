#ifndef  GRABBER
#define GRABBER

#include "grabber/grabberNotify.h"

template <typename PointT>
class Grabber
{
public:
	Grabber(GrabberNotify* grabberNotify) : _grabberNotify(grabberNotify)
	{
	}

	virtual void StartGrabber() = 0;
	virtual boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloud() = 0;
	virtual boost::mutex& GetMutex() = 0;
	virtual void StopGrabber() = 0;

protected:
	GrabberNotify* _grabberNotify;
};

#endif
