#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include "mainWindow.h"
#include "pModel.h"

MainWindow::MainWindow(PModel* pModel, QWidget *parent) : _pModel(pModel), QMainWindow(parent), _ui(new Ui::_mainWindow())
{
	_ui->setupUi(this);
	//	  event
	connect(_ui->_open3DFileBtn, SIGNAL(clicked()), this, SLOT(Open3DFileDialogSlot()));
	connect(_ui->_clearViewerBtn, SIGNAL(clicked()), this, SLOT(ClearViewerSlot()));
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
