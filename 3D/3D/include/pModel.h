#ifndef P_MODEL
#define P_MODEL

#include <chrono>
#include <thread>

#include "file/fileFactory.h"
#include "grabber/grabberNotify.h"
#include "grabber/grabberFactory.h"
#include "viewer/viewerNotify.h"
#include "viewer/viewer.h"
#include "arduino/Tserial.h"
#include "myPointCloud/myPointClouds.h"

typedef pcl::PointXYZRGBA PointT;

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
	boost::mutex& GetGrabberMutex();
	void UpdateNewCloudNotify();

	//				Arduino
	void MotorTurnLeft(int distance);
	void MotorTurnRight(int distance);
	void MotorReset();

	//			My Point Cloud
	void AddPointCloud(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name);
	int GetNumberOfPointCloud();
	void SetCloudOpacityById(int id, double value);
	double GetCloudOpacityById(int id);
	std::string GetCloudNameById(int id);
	boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloudById(int id);

private:
	ThreeDFile<PointT>* _currFile;
	FileFactory<PointT>* _fileFactory;
	Grabber<PointT>* _currGrabber;
	GrabberFactory<PointT>* _grabberFactory;
	GrabberNotify* _grabberNotify;
	ViewerNotify* _viewerNotify;
	Tserial* _arduino;
	MyPointClouds<PointT>* _pointClouds;
};

#endif