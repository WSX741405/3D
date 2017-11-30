#ifndef MY_POINT_CLOUD
#define MY_POINT_CLOID

#include <pcl/point_cloud.h>

template<typename PointT>
class MyPointCloud
{
public:
	MyPointCloud(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name = "Name") : _cloud(cloud), _name(name)
	{
		_opacity = 1;
	}

	void SetOpacity(double opacity)
	{
		_opacity = opacity;
	}

	double GetOpacity()
	{
		return _opacity;
	}

	std::string GetName()
	{
		return _name;
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetCloud()
	{
		return _cloud;
	}
private:
	std::string _name;
	double _opacity;
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif