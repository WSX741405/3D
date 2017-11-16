#ifndef  GRABBER_FACTORY
#define GRABBER_FACTORY

#include "grabber/grabber.h"
#include "grabber/rsGrabber.h"
#include "grabber/grabberNotify.h"

template <typename PointT>
class GrabberFactory
{
public:
	GrabberFactory(GrabberNotify* grabberNotify) : _grabberNotify(grabberNotify)
	{
	}

	Grabber<PointT>* GetRSGrabber()
	{
		static RSGrabber<PointT>* grabber = new RSGrabber<PointT>(_grabberNotify);
		return (Grabber<PointT>*)grabber;
	}

private:
	GrabberNotify* _grabberNotify;
};

#endif