/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__mainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *_open3DFileBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *_mainWindow)
    {
        if (_mainWindow->objectName().isEmpty())
            _mainWindow->setObjectName(QStringLiteral("_mainWindow"));
        _mainWindow->resize(688, 563);
        centralWidget = new QWidget(_mainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        _open3DFileBtn = new QPushButton(centralWidget);
        _open3DFileBtn->setObjectName(QStringLiteral("_open3DFileBtn"));
        _open3DFileBtn->setGeometry(QRect(30, 30, 75, 25));
        _mainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(_mainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 21));
        _mainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(_mainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        _mainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(_mainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        _mainWindow->setStatusBar(statusBar);

        retranslateUi(_mainWindow);

        QMetaObject::connectSlotsByName(_mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *_mainWindow)
    {
        _mainWindow->setWindowTitle(QApplication::translate("_mainWindow", "mainWindow", Q_NULLPTR));
        _open3DFileBtn->setText(QApplication::translate("_mainWindow", "Open 3D File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class _mainWindow: public Ui__mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
