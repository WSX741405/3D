#ifndef THREE_D_FILE
#define THREE_D_FILE

#include <string>

#include <pcl/io/io.h>

template <typename PointT>
class ThreeDFile
{
public:
	ThreeDFile(std::string dir) : _dir(dir)
	{
	}

	virtual void LoadFile() = 0;
	virtual boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloud() = 0;
protected:
	std::string _dir;
};

#endif