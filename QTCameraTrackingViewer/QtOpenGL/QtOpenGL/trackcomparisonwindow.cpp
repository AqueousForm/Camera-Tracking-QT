#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>
#include "trackcomparisonwindow.h"
#include "tools.h"

TrackComparisonWindow::TrackComparisonWindow(QWidget *parent)
	: QMainWindow(parent), filepath_("")
{
	ui.setupUi(this);
	ptr_glwidget_ = new RenderingWidget(this);
	/*vbox_layout_ = new QHBoxLayout(this);*/
	ui.verticalLayout->addWidget(ptr_glwidget_);
	QLabel *label_ = new QLabel(this->statusBar());
	label_->setText("3D Viewer test 16/02/28");
	this->statusBar()->addWidget(label_);
	CreateActions();

	// 	connect(ui.actionView_pictures, SIGNAL(triggered()), this, SLOT(ChangeToPictureWindow()));
}

TrackComparisonWindow::~TrackComparisonWindow()
{
}

void TrackComparisonWindow::Open()
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

void TrackComparisonWindow::VisualizeFrame()
{
	if (filepath_.isEmpty())
		return;

	ptr_glwidget_->LoadTransFromFile(filepath_.toStdString(), automation_disp->isChecked(), no_trans->isChecked(), cube_disp->isChecked());
}

void TrackComparisonWindow::CreateActions()
{
	// file menu
// 	connect(ui.actionOpen_file, SIGNAL(triggered()), this, SLOT(Open()));
// 	connect(ui.actionOpen_3D_points, SIGNAL(triggered()), this, SLOT(Open_3DPoint()));
// 	// view menu
// 	automation_disp = new QAction(this);
// 	automation_disp->setText("Automation");
// 	automation_disp->setCheckable(true);
// 
// 	complete_disp = new QAction(this);
// 	complete_disp->setText("Complete");
// 	complete_disp->setCheckable(true);
// 
// 	cube_disp = new QAction(this);
// 	cube_disp->setText("cube");
// 	cube_disp->setCheckable(true);
// 
// 	no_trans = new QAction(this);
// 	no_trans->setText("Undisplay Translation");
// 	no_trans->setCheckable(true);
// 
// 	with_trans = new QAction(this);
// 	with_trans->setText("Display Translation");
// 	with_trans->setCheckable(true);
// 
// 	with_3Dpoint = new QAction(this);
// 	with_3Dpoint->setText("with 3d points");
// 	with_3Dpoint->setCheckable(true);
// 
// 	no_3Dpoint = new QAction(this);
// 	no_3Dpoint->setText("no 3d points");
// 	no_3Dpoint->setCheckable(true);
// 
// 	ui.menuView_Mode->addAction(automation_disp);
// 	ui.menuView_Mode->addAction(complete_disp);
// 	ui.menuView_Mode->addAction(cube_disp);
// 	ui.menuView_Mode->addSeparator();
// 	ui.menuView_Mode->addAction(with_trans);
// 	ui.menuView_Mode->addAction(no_trans);
// 	ui.menuView_Mode->addSeparator();
// 	ui.menuView_Mode->addAction(with_3Dpoint);
// 	ui.menuView_Mode->addAction(no_3Dpoint);
// 
// 	QActionGroup *action_group2 = new QActionGroup(this);
// 	action_group2->addAction(automation_disp);
// 	action_group2->addAction(complete_disp);
// 	action_group2->addAction(cube_disp);
// 	automation_disp->setChecked(true);
// 
// 	QActionGroup *action_group3 = new QActionGroup(this);
// 	action_group3->addAction(with_trans);
// 	action_group3->addAction(no_trans);
// 	with_trans->setChecked(true);
// 
// 	QActionGroup *action_group4 = new QActionGroup(this);
// 	action_group4->addAction(with_3Dpoint);
// 	action_group4->addAction(no_3Dpoint);
// 	no_3Dpoint->setChecked(true);
// 
// 	connect(automation_disp, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
// 	connect(complete_disp, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
// 	connect(cube_disp, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
// 	connect(with_trans, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
// 	connect(no_trans, SIGNAL(triggered()), this, SLOT(VisualizeFrame()));
// 	connect(with_3Dpoint, SIGNAL(triggered()), this, SLOT(Visualize3DPoint()));
// 	connect(no_3Dpoint, SIGNAL(triggered()), this, SLOT(Visualize3DPoint()));
}


