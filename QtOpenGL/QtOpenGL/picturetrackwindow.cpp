#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>

#include "picturetrackwindow.h"
#include "picturetrackopenglwidget.h"
#include "tools.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
using std::string;
using std::cout;
using std::endl;
PictureTrackWindow::PictureTrackWindow(QWidget *parent)
	: QMainWindow(parent), filepath_(""), frame_1(NULL)
{
	ui.setupUi(this);

	// 	frame_1 = new Frame();
	// 	point3d_1 = new Points3D();
	ptr_picturetrackwidget_ = new PictureTrackOpenglWidget(this, &frame_1, ui.graphicsView);
	ptr_glwidget_ = ptr_picturetrackwidget_;

	ui.horizontalLayout_3->addWidget(ptr_glwidget_);
	
	//CreateActions();
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(Open()));

}

PictureTrackWindow::~PictureTrackWindow()
{
}

void PictureTrackWindow::Open()
{
	filepath_ = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		"C:\\Users\\szh\\Desktop\\O_KF_TransformsTotal",
		tr("Text Files(*.txt)"));
	frame_1 = new Frame();
	if (!filepath_.isEmpty())
	{
		GetFrameData();
	}
	else
	{
		filepath_ = "";
	}

}



void PictureTrackWindow::GetFrameData()
{
	if (filepath_.isEmpty())
		return;

	frame_1->LoadTransFromFile(filepath_.toStdString(), true, false, false);
}




