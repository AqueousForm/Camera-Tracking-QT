#include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>
#include "trackcomparisonopenglwidget.h"
#include "tools.h"
#include "ArcBall.h"

//typedef trimesh::vec3  Vec3f;
using std::vector;

TrackComparisonOpenglWidget::TrackComparisonOpenglWidget(QWidget *parent)
	: RenderingWidget(parent)
{
	ptr_arcball_ = new CArcBall(width(), height());

	eye_goal_[0] = 0.0;
	eye_goal_[1] = 0.0;
	eye_goal_[2] = 0.0;

	eye_direction_[0] = eye_direction_[1] = 0.0;
	eye_direction_[2] = 1.0;

	eye_distance_ = 15;

	automation_mode_ = true;
	disp_num_ = 0;

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimeOut()));
	timer->start(100);
}

TrackComparisonOpenglWidget::~TrackComparisonOpenglWidget()
{
	SAFEDELETE(ptr_arcball_);
}

void TrackComparisonOpenglWidget::Render()
{

}