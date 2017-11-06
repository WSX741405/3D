#ifndef OBJ_FILE
#define OBJ_FILE

#include <string>
#include <pcl/TextureMesh.h>
#include <pcl/io/io.h>
#include <pcl/io/obj_io.h>

#include "file/3DFile.h";

template <typename PointT>
class ObjFile : ThreeDFile<PointT>
{
public:
	ObjFile(std::string dir = "") : ThreeDFile(dir)
	{
		_cloud = new pcl::PointCloud<PointT>();
	}

	void LoadFile()
	{
		pcl::OBJReader obj;
		obj.read(_dir, *_cloud);
	}

	pcl::PointCloud<PointT>* GetCloud()
	{
		return _cloud;
	}

private:
	pcl::PointCloud<PointT>* _cloud;
};

#endif