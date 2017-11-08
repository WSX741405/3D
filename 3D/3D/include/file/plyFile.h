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
		_cloud = new pcl::PointCloud<PointT>();
	}

	void LoadFile()
	{
		pcl::io::loadPLYFile(_dir, *_cloud);
	}

	pcl::PointCloud<PointT>* GetCloud()
	{
		return _cloud;
	}

private:
	pcl::PointCloud<PointT>* _cloud;
};

#endif