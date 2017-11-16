#ifndef OBJ_FILE
#define OBJ_FILE

#include <string>
#include <pcl/TextureMesh.h>
#include <pcl/io/io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>

#include "file/3DFile.h";

template <typename PointT>
class ObjFile : ThreeDFile<PointT>
{
public:
	ObjFile(std::string dir = "") : ThreeDFile(dir)
	{
		//_cloud = new pcl::PointCloud<PointT>();
		_cloud = boost::shared_ptr<pcl::PointCloud<PointT>>(new pcl::PointCloud<PointT>);
	}

	void LoadFile()
	{
		pcl::PolygonMesh mesh;
		pcl::io::loadPolygonFile(_dir, mesh);
		//_cloud = new pcl::PointCloud<PointT>();
		pcl::fromPCLPointCloud2(mesh.cloud, *_cloud);
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetCloud()
	{
		return _cloud;
	}

private:
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif