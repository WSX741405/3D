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

	virtual void OpenGrabber() = 0;
	virtual boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloud() = 0;
	virtual void StopGrabber() = 0;
	virtual void UnlockMutex() = 0;

protected:
	GrabberNotify* _grabberNotify;
};

#endif
