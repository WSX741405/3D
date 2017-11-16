#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>
#include "ui_mainwindow.h"
#include "pModel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(PModel* pModel, QWidget* parent = 0);
	void InitialVtkWidget();
	void UpdateViewer();
	~MainWindow();

public slots:
	void Open3DFileDialogSlot();
	void ClearViewerSlot();
	void OpenRSGrabberSlot();

private:

	Ui::_mainWindow* _ui;
	Viewer<pcl::PointXYZRGBA>* _viewer;
	QVTKWidget* _widget;
	PModel* _pModel;
};

#endif 
