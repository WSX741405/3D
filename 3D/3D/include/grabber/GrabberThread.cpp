#include "GrabberThread.h"
//#include "PCL_ProcessModel.h"

GrabberThread::GrabberThread()
{
}

GrabberThread::~GrabberThread()
{
}

GrabberThread::GrabberThread(pModel *modelTemp)
{
	_model = modelTemp;
	_selectSensor = 0;
}

void GrabberThread::SetIsStop(bool temp)
{
	_isStop = temp;
}

bool GrabberThread::IsStop()
{
	return _isStop;
}

void GrabberThread::SetSelectSensor(int temp)
{
	_selectSensor = temp;
}

int GrabberThread::GetSelectSensor()
{
	return _selectSensor;
}

void GrabberThread::run()
{
	// Point Cloud
	pcl::PointCloud<PointT>::ConstPtr cloud;

	// Retrieved Point Cloud Callback Function
	boost::mutex mutex;
	boost::function<void(const pcl::PointCloud<PointT>::ConstPtr&)> function =
		[&cloud, &mutex](const pcl::PointCloud<PointT>::ConstPtr& ptr){
		boost::mutex::scoped_lock lock(mutex);
		cloud = ptr;
	};

	boost::shared_ptr<pcl::Grabber> grabber;

	switch (_selectSensor)
	{
	case 0:
	//	grabber = boost::make_shared<pcl::Kinect2Grabber>(); // Kinect2Grabber
		break;
	case 1:
	//	grabber = boost::make_shared<pcl::KinectGrabber>();  // KinectGrabber
		break;
	case 2:
		grabber = boost::make_shared<pcl::RealSenseGrabber>();
		break;
	default:
	//	grabber = boost::make_shared<pcl::Kinect2Grabber>(); // Kinect2Grabber
		break;
	}
	//if (isUseKinectV2)
	
	//else
	//	
	//grabber = boost::make_shared<pcl::RealSenseGrabber>();
	// Register Callback Function
	boost::signals2::connection connection = grabber->registerCallback(function);

	// Start Grabber
	grabber->start();

	while (!_isStop)
	{
		boost::mutex::scoped_try_lock lock(mutex);
		if (cloud && lock.owns_lock()){
			if (cloud->size() != 0){
				_model->SetGrabberResult(*cloud);
				//_model->UpdateResult();
			//	emit UpdateResultReady();
			}
		}
	}
}