#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <vtkRenderWindow.h>
#include <QVTKWidget.h>
#include "mainWindow.h"
#include "pModel.h"

MainWindow::MainWindow(PModel* pModel, QWidget *parent) : _pModel(pModel), QMainWindow(parent), _ui(new Ui::_mainWindow())
{
	_ui->setupUi(this);
	InitialVtkWidget();
	//	  event
	connect(_ui->_open3DFileBtn, SIGNAL(clicked()), this, SLOT(Open3DFileDialogSlot()));
	connect(_ui->_clearViewerBtn, SIGNAL(clicked()), this, SLOT(ClearViewerSlot()));
	connect(_ui->_openRSBtn, SIGNAL(clicked()), this, SLOT(OpenRSGrabberSlot()));
}

void MainWindow::InitialVtkWidget()
{
	//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
	//cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
	//boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	//viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	_widget = new QVTKWidget(this->centralWidget());
	_widget->setGeometry(QRect(20, 20, 500, 500));

	/*float radius = 10.0f;
	for (float theta(0.0); theta <= 360.0f; theta += 2.0f) {
		for (float phi(0.0); phi <= 180.0f; phi += 2.0f) {
			pcl::PointXYZ tmp_point;
			tmp_point.x = radius*cosf(pcl::deg2rad(theta))*sinf(pcl::deg2rad(phi));
			tmp_point.y = radius*sinf(pcl::deg2rad(theta))*sinf(pcl::deg2rad(phi));
			tmp_point.z = radius*cosf(pcl::deg2rad(phi));
			cloud->points.push_back(tmp_point);
		}
	}

	viewer->addPointCloud(cloud, "cloud");
	_widget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(_widget->GetInteractor(), _widget->GetRenderWindow());
	viewer->addCoordinateSystem(2.0);
	*/

	_widget->update();
}

MainWindow::~MainWindow()
{
}

void MainWindow::Open3DFileDialogSlot()
{
	QFileDialog openFileDialog(this);
	openFileDialog.setWindowTitle(tr("Open Point Cloud"));
	openFileDialog.setDirectory(".");
	openFileDialog.setNameFilter((QString)tr("OBJ(*.obj);;PLY(*.ply);;PCD(*.pcd)"));
	if (openFileDialog.exec() == QDialog::Accepted)
	{
		QString dir = openFileDialog.selectedFiles()[0];
		QString filter = openFileDialog.selectedNameFilter();
		_pModel->Open3DFile(std::string(dir.toLocal8Bit()), filter.toStdString());
	}
	else
	{
		QMessageBox::information(NULL, tr("Open Point Cloud"), tr("You didn't select any files."));
	}
}

void MainWindow::ClearViewerSlot()
{
	_pModel->ClearViewer();
}

void MainWindow::OpenRSGrabberSlot()
{
	_pModel->OpenRSGrabber();
}

void MainWindow::UpdateViewer()
{
	//_viewer->Show();
}