#ifndef OBJ_FILE
#define OBJ_FILE

#include <string>
#include <pcl/TextureMesh.h>
#include <pcl/io/io.h>
#include <pcl/io/vtk_lib_io.h>

#include "file/3DFile.h";

template <typename PointT>
class ObjFile : ThreeDFile<PointT>
{
public:
	ObjFile(std::string dir = "") : ThreeDFile(dir)
	{
	}

	void LoadFile()
	{
		pcl::io::loadPolygonFile(_dir, _mesh);
		_cloud = new pcl::PointCloud<PointT>();
		pcl::fromPCLPointCloud2(_mesh.cloud, *_cloud);
	}

	pcl::PointCloud<PointT>* GetCloud()
	{
		return _cloud;
	}

private:
	pcl::PolygonMesh _mesh;
	pcl::PointCloud<PointT>* _cloud;
};

#endif