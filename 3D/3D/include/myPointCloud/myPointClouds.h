#ifndef MY_POINT_CLOUDS
#define MY_POINT_CLOUDS

#include <vector>
#include <myPointCloud/myPointCloud.h>

template<typename PointT>
class MyPointClouds
{
public:
	MyPointClouds()
	{
		_clouds = std::vector<MyPointCloud<PointT>*>();
	}

	void AddPointCloud(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name = "Name")
	{
		MyPointCloud<PointT>* myCloud = new MyPointCloud<PointT>(cloud, name);
		_clouds.push_back(myCloud);
	}

	void SetOpacityById(int id, double opacity)
	{
		_clouds[id]->SetOpacity(opacity);
	}

	double GetOpacityById(int id)
	{
		return _clouds[id]->GetOpacity();
	}

	//	id = 0 ~ size - 1
	std::string GetNameById(int id)
	{
		return _clouds[id]->GetName();
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloudById(int id)
	{
		return _clouds[id]->GetCloud();
	}

	int GetNumberOfPointCloud()
	{
		return _clouds.size();
	}

private:
	std::vector<MyPointCloud<PointT>*> _clouds;
};

#endif