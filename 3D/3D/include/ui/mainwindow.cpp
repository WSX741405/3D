#include <QFileDialog>
#include <QMessageBox>
#include "mainWindow.h"
#include "pModel.h"

MainWindow::MainWindow(PModel* pModel, QWidget *parent) : _pModel(pModel), QMainWindow(parent) , _ui(new Ui::_mainWindow())
{
	_ui->setupUi(this);
	//	  event
	connect(_ui->_open3DFileBtn, SIGNAL(clicked()), this, SLOT(Open3DFileDialogSlot()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::Open3DFileDialogSlot()
{
	QFileDialog openFileDialog(this);
	openFileDialog.setWindowTitle(tr("Open 3D File"));
	openFileDialog.setDirectory(".");
	openFileDialog.setNameFilter((QString)tr("OBJ(*.obj);;PLY(*.ply);;PCD(*.pcd)"));
	if (openFileDialog.exec() == QDialog::Accepted) {
		QString dir = openFileDialog.selectedFiles()[0];
		QString filter = openFileDialog.selectedNameFilter();
	}
	else {
		QMessageBox::information(NULL, tr("Open 3D File"), tr("You didn't select any files."));
	}
}