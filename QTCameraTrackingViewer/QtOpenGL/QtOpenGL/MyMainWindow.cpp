#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>

#include "MyMainWindow.h"
#include "tools.h"

MyMainWindow::MyMainWindow(QWidget *parent)
	: QMainWindow(parent), picture_window_(NULL), opengl_window_(NULL)
{
	ui.setupUi(this);
// 	ptr_glwidget_ = new RenderingWidget(this);
// 	vbox_layout_ = new QHBoxLayout(this);
// 	vbox_layout_->addWidget(ptr_glwidget_);
// 
// 
// 
// 	ptr_glwidget_1 = new RenderingWidget(this);
// 	vbox_layout_1 = new QHBoxLayout(this);
// 	vbox_layout_1->addWidget(ptr_glwidget_1);
	
   // ui.verticalLayoutMain->setStretch(0, 0);
// 	ui.horizontalLayout_4->addLayout(vbox_layout_, 9);
// 	ui.horizontalLayout_4->addLayout(vbox_layout_1, 9);
	QLabel *label_ = new QLabel(this->statusBar());
	label_->setText("3D Viewer test 16/02/28");

	this->statusBar()->addWidget(label_);
// 	CreateActions();
// 	CreateActions_1();
	connect(ui.actionStart_2, SIGNAL(triggered()), this, SLOT(ChangeToPictureWindow()));
	connect(ui.actionStart, SIGNAL(triggered()), this, SLOT(ChangeToOpenglWindow()));
}

MyMainWindow::~MyMainWindow()
{
}

void MyMainWindow::ChangeToPictureWindow()
{
	//SAFEDELETE(picture_window_);
	picture_window_ = new PictureWindow(this);
	picture_window_->show();
	//this->hide();
}
void MyMainWindow::ChangeToOpenglWindow()
{
	//SAFEDELETE(opengl_window_);
	opengl_window_ = new OpenglWindow(this);
	opengl_window_->show();
	//this->hide();
}

/*
void MainWindow::Open()
{
	filepath_ = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		"C:\\Users\\szh\\Desktop\\O_KF_TransformsTotal",
		tr("Text Files(*.txt)"));
	if (!filepath_.isEmpty()) 
	{
		VisualizeFrame();
	}
	else 
	{
		filepath_ = "";
	}
}

void MainWindow::Open_1()
{
	filepath_1 = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		"C:\\Users\\szh\\Desktop\\O_KF_TransformsTotal",
		tr("Text Files(*.txt)"));
	if (!filepath_1.isEmpty())
	{
		VisualizeFrame_1();
	}
	else
	{
		filepath_1 = "";
	}
}


void MainWindow::Open_3DPoint()
{
	filepath_3DPoint = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		"C:\\Users\\szh\\Desktop\\O_KF_TransformsTotal",
		tr("Text Files(*.txt)"));
	if (!filepath_3DPoint.isEmpty())
	{
		Visualize3DPoint();
	}
	else
	{
		filepath_3DPoint = "";
	}
}

void MainWindow::VisualizeFrame()
{
	if (filepath_.isEmpty())
		return;

	ptr_glwidget_->LoadTransFromFile(filepath_.toStdString(), automation_disp->isChecked(), no_trans->isChecked(), cube_disp->isChecked());
}


void MainWindow::VisualizeFrame_1()
{
	if (filepath_1.isEmpty())
		return;

	ptr_glwidget_1->LoadTransFromFile(filepath_1.toStdString(), automation_disp_1->isChecked(), no_trans_1->isChecked(),cube_disp_1->isChecked());
}

void MainWindow::Visualize3DPoint()
{
	if (filepath_3DPoint.isEmpty())
		return;

	ptr_glwidget_->Load3DPointFromFile(filepath_3DPoint.toStdString(), with_3Dpoint->isChecked());
}
void MainWindow::CreateActions()
{
	// file menu
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(Open()));
	connect(ui.actionOpen_2, SIGNAL(triggered()), this, SLOT(Open_3DPoint()));
	// view menu
	automation_disp = new QAction(this);
	automation_disp->setText("Automation");
	automation_disp->setCheckable(true);

	complete_disp = new QAction(this);
	complete_disp->setText("Complete");
	complete_disp->setCheckable(true);

	cube_disp = new QAction(this);
	cube_disp->setText("cube");
	cube_disp->setCheckable(true);

	no_trans = new QAction(this);
	no_trans->setText("Undisplay Translation");
	no_trans->setCheckable(true);

	with_trans = new QAction(this);
	with_trans->setText("Display Translation");
	with_trans->setCheckable(true);

	with_3Dpoint = new QAction(this);
	with_3Dpoint->setText("with 3d points");
	with_3Dpoint->setCheckable(true);

	no_3Dpoint = new QAction(this);
	no_3Dpoint->setText("no 3d points");
	no_3Dpoint->setCheckable(true);

	ui.menuView->addAction(automation_disp);
	ui.menuView->addAction(complete_disp);
	ui.menuView->addAction(cube_disp);
	ui.menuView->addSeparator();
	ui.menuView->addAction(with_trans);
	ui.menuView->addAction(no_trans);
	ui.menuView->addSeparator();
	ui.menuView->addAction(with_3Dpoint);
	ui.menuView->addAction(no_3Dpoint);

	QActionGroup *action_group2 = new QActionGroup(this);
	action_group2->addAction(automation_disp);
	action_group2->addAction(complete_disp);
	action_group2->addAction(cube_disp);
	automation_disp->setChecked(true);

	QActionGroup *action_group3 = new QActionGroup(this);
	action_group3->addAction(with_trans);
	action_group3->addAction(no_trans);
	with_trans->setChecked(true);

	QActionGroup *action_group4 = new QActionGroup(this);
	action_group4->addAction(with_3Dpoint);
	action_group4->addAction(no_3Dpoint);
	no_3Dpoint->setChecked(true);

	connect(automation_disp, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
	connect(complete_disp, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
	connect(cube_disp, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
	connect(with_trans, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
	connect(no_trans, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
	connect(with_3Dpoint, SIGNAL(triggered()), this, SLOT(Visualize3DPoint()));
	connect(no_3Dpoint, SIGNAL(triggered()), this, SLOT(Visualize3DPoint()));
}


void MainWindow::CreateActions_1()
{
	// file menu
	connect(ui.actionOpen_1, SIGNAL(triggered()), this, SLOT(Open_1()));

	// view menu
	automation_disp_1 = new QAction(this);
	automation_disp_1->setText("Automation");
	automation_disp_1->setCheckable(true);

	complete_disp_1 = new QAction(this);
	complete_disp_1->setText("Complete");
	complete_disp_1->setCheckable(true);


	cube_disp_1 = new QAction(this);
	cube_disp_1->setText("cube");
	cube_disp_1->setCheckable(true);

	no_trans_1 = new QAction(this);
	no_trans_1->setText("Undisplay Translation");
	no_trans_1->setCheckable(true);
			
	with_trans_1 = new QAction(this);
	with_trans_1->setText("Display Translation");
	with_trans_1->setCheckable(true);

	ui.menuView2->addAction(automation_disp_1);
	ui.menuView2->addAction(complete_disp_1);
	ui.menuView2->addAction(cube_disp_1);
	ui.menuView2->addSeparator();
	ui.menuView2->addAction(with_trans_1);
	ui.menuView2->addAction(no_trans_1);

	QActionGroup *action_group2_1 = new QActionGroup(this);
	action_group2_1->addAction(automation_disp_1);
	action_group2_1->addAction(complete_disp_1);
	action_group2_1->addAction(cube_disp_1);
	automation_disp_1->setChecked(true);

	QActionGroup *action_group3_1 = new QActionGroup(this);
	action_group3_1->addAction(with_trans_1);
	action_group3_1->addAction(no_trans_1);
	with_trans_1->setChecked(true);


	connect(automation_disp_1, SIGNAL(triggered()), this, SLOT(VisualizeFrame_1()));
	connect(complete_disp_1, SIGNAL(triggered()), this, SLOT(VisualizeFrame_1()));
	connect(cube_disp_1, SIGNAL(triggered()), this, SLOT(VisualizeFrame_1()));
	connect(with_trans_1, SIGNAL(triggered()), this, SLOT(VisualizeFrame_1()));
	connect(no_trans_1, SIGNAL(triggered()), this, SLOT(VisualizeFrame_1()));
}
*/