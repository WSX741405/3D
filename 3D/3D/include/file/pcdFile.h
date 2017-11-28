#ifndef PCD_FILE
#define PCD_FILE

#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>

template <typename PointT>
class PcdFile : ThreeDFile<PointT>
{
public:
	PcdFile(std::string dir = "") : ThreeDFile(dir)
	{
		//_cloud = new pcl::PointCloud<PointT>();
		_cloud.reset(new pcl::PointCloud<PointT>);
	}

	void LoadFile()
	{
		//pcl::io::loadPCDFile(_dir, *_cloud);
		pcl::PCDReader reader;
		reader.read(_dir, *_cloud);
		for (size_t index = 0; index < _cloud->points.size(); index++)
			_cloud->points[index].a = 255;
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloud()
	{
		return _cloud;
	}

private:
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif