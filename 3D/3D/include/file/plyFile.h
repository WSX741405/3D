#ifndef PLY_FILE
#define PLY_FILE

#include <pcl/io/io.h>
#include <pcl/io/ply_io.h>

#include "file/3DFile.h";

template <typename PointT>
class PlyFile : ThreeDFile<PointT>
{
public:
	PlyFile(std::string dir = "") : ThreeDFile(dir)
	{
		//_cloud = new pcl::PointCloud<PointT>();
		_cloud.reset(new pcl::PointCloud<PointT>);
	}

	void LoadFile()
	{
		//pcl::io::loadPLYFile(_dir, *_cloud);
		pcl::PLYReader reader;
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