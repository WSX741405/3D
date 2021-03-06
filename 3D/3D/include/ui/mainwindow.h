#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <vtkRenderWindow.h>
#include "ui_mainwindow.h"
#include "viewer/viewer.h"
#include "viewer/viewerNotify.h"
#include "pModel.h"

typedef pcl::PointXYZRGBA PointT;

class ViewerNotify;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(PModel* pModel, ViewerNotify* viewerNotify, QWidget* parent = 0);
	void UpdatePointCloudTable();
	void UpdateVTKViewer();
	~MainWindow();

public slots:
	void Open3DFileDialogSlot();
	//void ClearViewerSlot();
	void StartRSGrabberSlot();
	void StopGrabberSlot();
	void MotorTurnLeftSlot();
	void MotorTurnRightSlot();
	void TableItemCheckedSlots(QTableWidgetItem* item);

private:
	void InitialVtkWidget();
	void InitialPointCloudTable();

	bool _isUpdateTable;
	Ui::_mainWindow* _ui;
	Viewer<PointT>* _viewer;
	ViewerNotify* _viewerNotify;
	QVTKWidget* _widget;
	PModel* _pModel;
};

#endif 
