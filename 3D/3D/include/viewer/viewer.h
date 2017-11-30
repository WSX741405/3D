#ifndef VIEWER
#define VIEWER

#include <pcl/visualization/cloud_viewer.h>
#include <vtkRenderWindow.h>

template<typename PointT>
class Viewer
{
public:
	Viewer(std::string title = "") : _title(title)
	{
		//_viewer = new pcl::visualization::PCLVisualizer(_title, false);
		_viewer.reset(new pcl::visualization::PCLVisualizer(_title, false));
		//_viewer->setBackgroundColor(255, 255, 255);
	}

	void SetCloudOpacity(std::string name, double value)
	{
		_viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_OPACITY, value, name);
	}

	void Show(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name)
	{
		if(!_viewer->updatePointCloud(cloud, name))
			_viewer->addPointCloud(cloud, name);
	}

	void ResetCamera()
	{
		_viewer->resetCamera();
	}

	void SetupInteractor(QVTKInteractor* interactor, vtkRenderWindow* renderWindow)
	{
		_viewer->setupInteractor(interactor, renderWindow);
	}

	vtkRenderWindow* GetRenderWindow()
	{
		 return _viewer->getRenderWindow();
	}

	void AddCoordinateSystem(double coorSys)
	{
		_viewer->addCoordinateSystem(coorSys);
	}

private:
	std::string _title;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> _viewer;
};

#endif