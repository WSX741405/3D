#ifndef POINT_CLOUD_MANAGER
#define POINT_CLOUD_MANAGER

#include <vector>
#include <pcl/point_cloud.h>

template<typename PointT>
class PointCloudManager
{
public:
	PointCloudManager()
	{
	}
private:
	std::vector<boost::shared_ptr<pcl::PointCloud<PointT>>> _clouds;
};

#endif