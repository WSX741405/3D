#ifndef VIEWER
#define VIEWER

#include <pcl/visualization/cloud_viewer.h>

template<typename PointT>
class Viewer
{
public:
	Viewer(std::string title = "") : _title(title)
	{
		_viewer = new pcl::visualization::PCLVisualizer(_title);
		_viewerPtr = boost::shared_ptr<pcl::visualization::PCLVisualizer>(_viewer);
	}

	void Show(pcl::PointCloud<PointT>* cloud)
	{
		pcl::PointCloud<PointT>::Ptr cloudPtr(cloud);
		_cloudPtr = boost::shared_ptr<pcl::PointCloud<PointT>>(cloud);
		_viewerPtr->addPointCloud<PointT>(_cloudPtr);
	}

private:
	std::string _title;
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloudPtr;
	pcl::visualization::PCLVisualizer* _viewer;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> _viewerPtr;
};

#endif