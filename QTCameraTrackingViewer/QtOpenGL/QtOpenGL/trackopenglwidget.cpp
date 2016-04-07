#include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>
#include "trackopenglwidget.h"
#include "tools.h"
#include "ArcBall.h"

//using std::vector;
TrackOpenglWidget::TrackOpenglWidget(QWidget *parent, Frame **frame, Points3D  ***point)
	: RenderingWidget(parent)
{
	ptr_arcball_ = new CArcBall(width(), height());

	eye_goal_[0] = 0.0;
	eye_goal_[1] = 0.0;
	eye_goal_[2] = 0.0;

	eye_direction_[0] = eye_direction_[1] = 0.0;
	eye_direction_[2] = 1.0;
	eye_distance_ = 15;
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimeOut()));
	timer->start(100);
	frame_1 = frame;
	points3d_ = point;
}

TrackOpenglWidget::~TrackOpenglWidget()
{
	SAFEDELETE(ptr_arcball_);
}

void TrackOpenglWidget::Render()
{
	if ((*frame_1) != NULL){
		if ((*frame_1)->cube_mode_){
			(*frame_1)->DrawCube();
		}
		else (*frame_1)->DrawFrame();
	}
	if ((*points3d_ )!= NULL){
		for (int i = 0; i < (*points3d_)[0]->total_num_; i++){
			(*points3d_)[i]->Draw3DPoints();
		}
	}
}

void TrackOpenglWidget::TimeOut()
{

	updateGL();
}
