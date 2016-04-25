#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>

#include "trackwindow.h"
#include "trackopenglwidget.h"
#include "tools.h"
#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::cout;
using std::endl;
TrackWindow::TrackWindow(QWidget *parent)
	: QMainWindow(parent), filepath_(""), points3d_(NULL), frame_1(NULL)
{
	ui.setupUi(this);

	// 	frame_1 = new Frame();
	// 	point3d_1 = new Points3D();
	ptr_trackwidget_ = new TrackOpenglWidget(this, &frame_1, &points3d_);
	ptr_glwidget_ = ptr_trackwidget_;

	ui.verticalLayout->addWidget(ptr_glwidget_);
	QLabel *label_ = new QLabel(this->statusBar());
	label_->setText("3D Viewer test 16/02/28");
	this->statusBar()->addWidget(label_);
	CreateActions();


}

TrackWindow::~TrackWindow()
{
}

void TrackWindow::Open()
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

void TrackWindow::Open_3DPoint()
{

	filepath_3DPoint = QFileDialog::getOpenFileNames(this,
		tr("Open File"),
		".\\",
		tr("Text Files(*.txt)"));
	total_num = filepath_3DPoint.size();
	//cout << total_num << endl;
	filepath_transform = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		".\\",
		tr("Text Files(*.txt)"));
	points3d_ = new Points3D *[total_num];
	for (int i = 0; i < total_num; i++){
		points3d_[i] = new Points3D();
	}

	GetAll3DPointData();
}


void TrackWindow::GetFrameData()
{
	if (filepath_.isEmpty())
		return;

	frame_1->LoadTransFromFile(filepath_.toStdString(), automation_disp->isChecked(), no_trans->isChecked(), cube_disp->isChecked());
}

void TrackWindow::GetAll3DPointData(){
	string line;
	Eigen::MatrixXf RT(4, 4), RT_inv(4, 4);
	std::ifstream fin(filepath_transform.toStdString());
	if (!fin)
	{
		/*QMessageBox::warning(this, "Warning", "No such file!", 0, 1, 0);*/
		printf("error!/n");
		return;
	}

	for (int i = 0; i < total_num; i++){

		if (i != 0){
			char c;
			fin >> c;
			while (!isdigit(c) && c != '-'&&c != EOF){
				getline(fin, line, '#');
				fin >> c;

			}
			if (fin.eof())
				break;
			fin.putback(c);
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					fin >> RT(j, k);
			RT_inv = RT.inverse();
			Get3DPointData(RT_inv, i);
		}
		else {
			RT_inv = Eigen::MatrixXf::Identity(4, 4);
			Get3DPointData(RT_inv, i);

		}
	}
	fin.close();
}
void TrackWindow::Get3DPointData(Eigen::MatrixXf RT, int i)
{
	if (filepath_3DPoint.isEmpty())
		return;

	points3d_[i]->Load3DPointFromFile(filepath_3DPoint[i].toStdString(), with_3Dpoint->isChecked(), RT, total_num);
}
void TrackWindow::CreateActions()
{
	// file menu
	connect(ui.actionOpen_file, SIGNAL(triggered()), this, SLOT(Open()));
	connect(ui.actionOpen_3D_points, SIGNAL(triggered()), this, SLOT(Open_3DPoint()));
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

	ui.menuView_Mode->addAction(automation_disp);
	ui.menuView_Mode->addAction(complete_disp);
	ui.menuView_Mode->addAction(cube_disp);
	ui.menuView_Mode->addSeparator();
	ui.menuView_Mode->addAction(with_trans);
	ui.menuView_Mode->addAction(no_trans);
	ui.menuView_Mode->addSeparator();
	ui.menuView_Mode->addAction(with_3Dpoint);
	ui.menuView_Mode->addAction(no_3Dpoint);

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

	connect(automation_disp, SIGNAL(triggered()), this, SLOT(GetFrameData()));
	connect(complete_disp, SIGNAL(triggered()), this, SLOT(GetFrameData()));
	connect(cube_disp, SIGNAL(triggered()), this, SLOT(GetFrameData()));
	connect(with_trans, SIGNAL(triggered()), this, SLOT(GetFrameData()));
	connect(no_trans, SIGNAL(triggered()), this, SLOT(GetFrameData()));
	connect(with_3Dpoint, SIGNAL(triggered()), this, SLOT(GetAll3DPointData()));
	connect(no_3Dpoint, SIGNAL(triggered()), this, SLOT(GetAll3DPointData()));
}


