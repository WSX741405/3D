#include "pModel.h"

PModel::PModel() : _currFile(NULL)
{
	_fileFactory = new FileFactory<PointT>();
	_grabberNotify = new GrabberNotify(this);
	_grabberFactory = new GrabberFactory<PointT>(_grabberNotify);
	_pointClouds = new MyPointClouds<PointT>();
	_arduino = new Tserial();
	if (_arduino != 0)
		_arduino->connect("com4", 9600, spNONE);
	MotorReset();
}

void PModel::SetViewerNotify(ViewerNotify* viewerNotify)
{
	_viewerNotify = viewerNotify;
}

void PModel::Open3DFile(std::string dir, std::string filter)
{
	if (filter == std::string("OBJ(*.obj)"))
	{
		_currFile = _fileFactory->GetObjFile(dir);
	}
	else if (filter == std::string("PLY(*.ply)"))
	{
		_currFile = _fileFactory->GetPlyFile(dir);
	}
	else if (filter == std::string("PCD(*.pcd)"))
	{
		_currFile = _fileFactory->GetPcdFile(dir);
	}
	_currFile->LoadFile();
	AddPointCloud(GetFilePointCloud(), dir);
	_viewerNotify->UpdatePointCloudNotify();
}

boost::shared_ptr<pcl::PointCloud<PointT>> PModel::GetFilePointCloud()
{
	return _currFile->GetPointCloud();
}

//*******************************************************************************
//				Grabber
//*******************************************************************************
void PModel::OpenRSGrabber()
{
	_currGrabber = _grabberFactory->GetRSGrabber();
	_currGrabber->OpenGrabber();
}

void PModel::UpdateNewCloudNotify()
{
	static int index = 0;
	AddPointCloud(GetGrabberPointCloud(), "rs" + std::to_string(index++));
	_viewerNotify->UpdatePointCloudNotify();
}

boost::shared_ptr<pcl::PointCloud<PointT>> PModel::GetGrabberPointCloud()
{
	return _currGrabber->GetPointCloud();
}

boost::mutex& PModel::GetGrabberMutex()
{
	return _currGrabber->GetMutex();
}

//*******************************************************************************
//				Arduino
//*******************************************************************************
void PModel::MotorTurnLeft(int degree)
{
	//			0    Turn Left
	unsigned char dir = '0' & 0xff;;
	unsigned char deg = (degree + '0') & 0xff;;
	_arduino->sendChar(dir);
	_arduino->sendChar(deg);
}

void PModel::MotorTurnRight(int degree)
{
	//			1    Turn Right
	unsigned char dir = '1' & 0xff;;
	unsigned char deg = (degree + '0') & 0xff;;
	_arduino->sendChar(dir);
	_arduino->sendChar(deg);
}

void PModel::MotorReset()
{
	unsigned char dir = '2' & 0xff;;
	unsigned char dis = '0' & 0xff;;
	_arduino->sendChar(dir);
	_arduino->sendChar(dis);
}

//*******************************************************************************
//				Point Cloud
//*******************************************************************************
void PModel::AddPointCloud(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name = "Name")
{
	_pointClouds->AddPointCloud(cloud, name);
}

int PModel::GetNumberOfPointCloud()
{
	return _pointClouds->GetNumberOfPointCloud();
}

void PModel::SetCloudOpacityById(int id, double value)
{
	_pointClouds->SetOpacityById(id, value);
}

double PModel::GetCloudOpacityById(int id)
{
	return _pointClouds->GetOpacityById(id);
}

std::string PModel::GetCloudNameById(int id)
{
	return _pointClouds->GetNameById(id);
}

boost::shared_ptr<pcl::PointCloud<PointT>> PModel::GetPointCloudById(int id)
{
	return _pointClouds->GetPointCloudById(id);
}
