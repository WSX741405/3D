#ifndef P_MODEL
#define P_MODEL

#include <chrono>
#include <thread>

#include "file/fileFactory.h"
#include "grabber/grabberNotify.h"
#include "grabber/grabberFactory.h"
#include "viewer/viewerNotify.h"
#include "viewer/viewer.h"

typedef pcl::PointXYZ PointT;

class ViewerNotify;

class PModel
{
public:
	PModel();

	void SetViewerNotify(ViewerNotify* viewerNotify);

	//				File
	void Open3DFile(std::string dir, std::string filter);
	boost::shared_ptr<pcl::PointCloud<PointT>> GetFilePointCloud();

	//				Grabber
	void OpenRSGrabber();
	boost::shared_ptr<pcl::PointCloud<PointT>> GetGrabberPointCloud();
	void UpdateNewCloudNotify();

private:
	FileFactory<PointT>* _fileFactory;
	GrabberFactory<PointT>* _grabberFactory;
	GrabberNotify* _grabberNotify;
	ViewerNotify* _viewerNotify;
	ThreeDFile<PointT>* _currFile;
	Grabber<PointT>* _currGrabber;
};

#endif