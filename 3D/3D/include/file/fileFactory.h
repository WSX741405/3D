#ifndef FILE_FACTORY
#define FILE_FACTORY

#include "file/3DFile.h";
#include "file/objFile.h";

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
};

#endif