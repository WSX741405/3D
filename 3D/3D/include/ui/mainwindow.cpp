#include "mainWindow.h"

MainWindow::MainWindow(PModel* pModel, ViewerNotify* viewerNotify, QWidget *parent) : _pModel(pModel), _viewerNotify(viewerNotify), QMainWindow(parent), _ui(new Ui::_mainWindow())
{
	_ui->setupUi(this);
	_viewer = new Viewer<PointT>();
	_viewerNotify->Attach(this);
	_pModel->SetViewerNotify(viewerNotify);
	_isUpdateTable = false;
	InitialVtkWidget();
	InitialPointCloudTable();
	//	  event
	connect(_ui->_openFileMenu, SIGNAL(triggered()), this, SLOT(Open3DFileDialogSlot()));
	//connect(_ui->_clearViewerBtn, SIGNAL(clicked()), this, SLOT(ClearViewerSlot()));
	connect(_ui->_openRSMenu, SIGNAL(triggered()), this, SLOT(OpenRSGrabberSlot()));
	connect(_ui->_motorTurnLeftBtn, SIGNAL(pressed()), this, SLOT(MotorTurnLeftSlot()));
	connect(_ui->_motorTurnRightBtn, SIGNAL(pressed()), this, SLOT(MotorTurnRightSlot()));
	connect(_ui->_pointCloudTable, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(TableItemCheckedSlots(QTableWidgetItem *)));
}

void MainWindow::InitialVtkWidget()
{
	_widget = new QVTKWidget(this->centralWidget());
	_widget->setGeometry(QRect(30, 30, 540, 540));

	_widget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_widget->GetInteractor(), _widget->GetRenderWindow());
	_widget->update();
}

void MainWindow::InitialPointCloudTable()
{
	_ui->_pointCloudTable->setRowCount(0);
	_ui->_pointCloudTable->setColumnCount(2);
	_ui->_pointCloudTable->setColumnWidth(0, 400);
	QStringList tableTitle;
	tableTitle << QString("Name") << QString("Show");
	for (int counter = 0; counter < _ui->_pointCloudTable->horizontalHeader()->count(); ++counter)
	{
		_ui->_pointCloudTable->horizontalHeader()->setSectionResizeMode(counter, QHeaderView::Stretch);
	}
	_ui->_pointCloudTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	_ui->_pointCloudTable->setHorizontalHeaderLabels(tableTitle);
}

void MainWindow::UpdatePointCloudTable()
{
	_isUpdateTable = true;
	int counter;
	int numberOfClouds = _pModel->GetNumberOfPointCloud();
	_ui->_pointCloudTable->setRowCount(numberOfClouds);
	for (counter = 0; counter < numberOfClouds; counter++)
	{
		QString name = QString::fromStdString(_pModel->GetCloudNameById(counter));
		_ui->_pointCloudTable->setItem(counter, 0, new QTableWidgetItem(name));

		QTableWidgetItem *displayItem = new QTableWidgetItem();
		if (_pModel->GetCloudOpacityById(counter) == 1)
			displayItem->setCheckState(Qt::Checked);
		else
			displayItem->setCheckState(Qt::Unchecked);
		_ui->_pointCloudTable->setItem(counter, 1, displayItem);
	}
	_isUpdateTable = false;
}

void MainWindow::UpdateVTKViewer()
{
	int counter;
	int numberOfClouds = _pModel->GetNumberOfPointCloud();
	for (counter = 0; counter < numberOfClouds; counter++)
	{
		std::string name = _pModel->GetCloudNameById(counter);
		_viewer->Show(_pModel->GetPointCloudById(counter), name);
		_viewer->SetCloudOpacity(_pModel->GetCloudNameById(counter), _pModel->GetCloudOpacityById(counter));
	}
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
		//QString name = openFileDialog.selectedFiles;
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
	_pModel->MotorTurnLeft(5);
}

void MainWindow::MotorTurnRightSlot()
{
	_pModel->MotorTurnRight(5);
}

void MainWindow::TableItemCheckedSlots(QTableWidgetItem* item)
{
	if (_isUpdateTable)
		return;
	int row = item->row();
	double opacity;
	if (item->checkState() == Qt::Checked)
		opacity = 1;
	else
		opacity = 0;
	_pModel->SetCloudOpacityById(row, opacity);
	UpdateVTKViewer();
}