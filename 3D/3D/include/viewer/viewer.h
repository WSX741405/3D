#ifndef VIEWER
#define VIEWER

#include <pcl/visualization/cloud_viewer.h>

template<typename PointT>
class Viewer
{
public:
	Viewer(std::string title = "") : _title(title)
	{
		_viewerPtr = boost::shared_ptr<pcl::visualization::PCLVisualizer>(new pcl::visualization::PCLVisualizer(_title));
	}

	void Clear()
	{
		_viewerPtr->removeAllPointClouds();
	}

	void Show(boost::shared_ptr<pcl::PointCloud<PointT>> cloud)
	{
		_viewerPtr->removePointCloud();
		_viewerPtr->addPointCloud(cloud);
		_viewerPtr->resetCamera();
	}

private:
	std::string _title;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> _viewerPtr;
};

#endif