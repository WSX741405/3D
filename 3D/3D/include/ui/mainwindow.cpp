#include "mainWindow.h"

MainWindow::MainWindow(PModel* pModel, ViewerNotify* viewerNotify, QWidget *parent) : _pModel(pModel),_viewerNotify(viewerNotify), QMainWindow(parent), _ui(new Ui::_mainWindow())
{
	_ui->setupUi(this);
	_viewer = new Viewer<PointT>();
	_viewerNotify->Attach(this);
	_pModel->SetViewerNotify(viewerNotify);
	InitialVtkWidget();
	//	  event
	connect(_ui->_openFileMenu, SIGNAL(triggered()), this, SLOT(Open3DFileDialogSlot()));
	//connect(_ui->_clearViewerBtn, SIGNAL(clicked()), this, SLOT(ClearViewerSlot()));
	connect(_ui->_openRSMenu, SIGNAL(triggered()), this, SLOT(OpenRSGrabberSlot()));
	connect(_ui->_motorTurnLeftBtn, SIGNAL(pressed()), this, SLOT(MotorTurnLeftSlot()));
	connect(_ui->_motorTurnRightBtn, SIGNAL(pressed()), this, SLOT(MotorTurnRightSlot()));
}

void MainWindow::InitialVtkWidget()
{
	_widget = new QVTKWidget(this->centralWidget());
	_widget->setGeometry(QRect(30, 30, 540, 540));

	_widget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_widget->GetInteractor(), _widget->GetRenderWindow());
	//_viewer->AddCoordinateSystem(2.0);
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

/*
void MainWindow::ClearViewerSlot()
{
	_pModel->ClearViewer();
}
*/

void MainWindow::OpenRSGrabberSlot()
{
	_pModel->OpenRSGrabber();
}

void MainWindow::MotorTurnLeftSlot()
{
	_pModel->MotorTurnLeft(1);
}

void MainWindow::MotorTurnRightSlot()
{
	_pModel->MotorTurnRight(1);
}

void MainWindow::ShowFilePointCloud()
{
	_viewer->Show(_pModel->GetFilePointCloud());
	_widget->update();
}

void MainWindow::ShowGrabberPointCloud()
{
	_viewer->Show(_pModel->GetGrabberPointCloud());
	_widget->update();
}