#ifndef FILE_FACTORY
#define FILE_FACTORY

#include "file/3DFile.h";
#include "file/objFile.h";
#include "file/plyFile.h";
#include "file/pcdFile.h";

template<typename PointT>
class FileFactory
{
public:
	FileFactory()
	{
	}

	ThreeDFile<PointT>* GetObjFile(std::string dir = "")
	{
		ObjFile<PointT>* file = new ObjFile<PointT>(dir);
		return (ThreeDFile<PointT>*)file;
	}

	ThreeDFile<PointT>* GetPlyFile(std::string dir = "")
	{
		PlyFile<PointT>* file = new PlyFile<PointT>(dir);
		return (ThreeDFile<PointT>*)file;
	}

	ThreeDFile<PointT>* GetPcdFile(std::string dir = "")
	{
		PcdFile<PointT>* file = new PcdFile<PointT>(dir);
		return (ThreeDFile<PointT>*)file;
	}
};

#endif