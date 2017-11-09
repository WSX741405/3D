#ifndef VIEWER
#define VIEWER

#include <pcl/visualization/cloud_viewer.h>

template<typename PointT>
class Viewer
{
public:
	Viewer(std::string title = "") : _title(title)
	{
		_cloudPointId = 0;
		_viewer = new pcl::visualization::PCLVisualizer(_title);
		_viewerPtr = boost::shared_ptr<pcl::visualization::PCLVisualizer>(_viewer);
	}

	void Clear()
	{
		_viewerPtr->removeAllPointClouds();
		_cloudPointId = 0;
	}

	void Show(pcl::PointCloud<PointT>* cloud)
	{
		boost::shared_ptr<pcl::PointCloud<PointT>>cloudShrPtr(cloud);
		_viewerPtr->addPointCloud<PointT>(cloudShrPtr, std::to_string(_cloudPointId));
		_viewerPtr->resetCamera();
		_cloudPointId++;
	}

private:
	int _cloudPointId;
	std::string _title;
	pcl::visualization::PCLVisualizer* _viewer;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> _viewerPtr;
};

#endif