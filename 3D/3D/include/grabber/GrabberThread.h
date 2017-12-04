#pragma once
#include <QThread>
#include "grabber/rsgrabber/real_sense_grabber.h"

typedef pcl::PointXYZRGBA PointT;

class pModel;

class GrabberThread : public QThread
{
	Q_OBJECT
public:
	GrabberThread();
	GrabberThread(pModel *modelTemp);
	void SetIsStop(bool temp);
	bool IsStop();
	void SetSelectSensor(int temp);
	int GetSelectSensor();
	~GrabberThread();

protected:
	void run();

signals:
	void UpdateResultReady();
private:
	bool _isStop;
	pModel*_model;
	int _selectSensor;
};

