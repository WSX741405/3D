#ifndef VIEWER
#define VIEWER

#include <pcl/visualization/cloud_viewer.h>

template<typename PointT>
class Viewer
{
public:
	Viewer(std::string title = "") : _title(title)
	{
		_viewer = new pcl::visualization::CloudViewer(_title);
	}

	void Show(pcl::PointCloud<PointT>* cloud)
	{
		pcl::PointCloud<PointT>::Ptr cloudPtr(cloud);
		_viewer->showCloud(cloudPtr);
		while (!_viewer->wasStopped())
		{
		}
	}

private:
	std::string _title;
	pcl::visualization::CloudViewer* _viewer;
};

#endif