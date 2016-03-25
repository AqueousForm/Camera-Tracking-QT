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
using namespace std;
TrackComparisonOpenglWidget::TrackComparisonOpenglWidget(QWidget *parent, Trajectory * trajectory[])
	: RenderingWidget(parent)
{
	ptr_arcball_ = new CArcBall(width(), height());

	eye_goal_[0] = 0.0;
	eye_goal_[1] = 0.0;
	eye_goal_[2] = 0.0;

	eye_direction_[0] = eye_direction_[1] = 0.0;
	eye_direction_[2] = 1.0;

	eye_distance_ = 15;
	for (int j = 0; j < 10; j++){
		trajectory_[j] = trajectory[j];
	}

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

	num = trajectory_[0]->total_num_;
	for (int i = 0; i < num; i++){
		trajectory_[i]->DrawTrajectory();
	}
}
void TrackComparisonOpenglWidget::mousePressEvent(QMouseEvent *e)
{
	switch (e->button())
	{
	case Qt::LeftButton:
		ptr_arcball_->MouseDown(e->pos());
		break;
	case Qt::MidButton:
		current_position_ = e->pos();
		break;
	default:
		break;
	}
	if (e->buttons()&Qt::RightButton)//鼠标右键
	{
		GLfloat px;
		GLfloat py;
		GLfloat winx;
		GLfloat winy;
		GLfloat winz;
		GLdouble posx, posy, posz;
		QPoint lastPos;
		lastPos = e->pos();
		px = lastPos.x();
		py = lastPos.y();
		GLint viewport[4];
		GLdouble mvmatrix[16], projmatrix[16];
		glPushMatrix();
		glMultMatrixf(ptr_arcball_->GetBallMatrix());
		//glRotatef(-30.0, 0.0, 0.0, 1.0);//之前绘图时进行的旋转
		glGetIntegerv(GL_VIEWPORT, viewport);
		glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
		glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
		glPopMatrix();
		winx = px;
		winy = (float)viewport[3] - py;//windows下y值机制和opengl中不一样
		glReadPixels((int)winx, (int)winy, 1, 1,
			GL_DEPTH_COMPONENT, GL_FLOAT, &winz);//从帧缓冲区读取鼠标点深度信息
		gluUnProject((GLdouble)winx, (GLdouble)winy,
			(GLdouble)winz, mvmatrix, projmatrix, viewport, &posx, &posy, &posz);
		cout << lastPos.x() << ' ' << lastPos.y() << ' ' << winx << ' ' << winy << ' ' << posx << ' ' << posy << ' ' << posz << endl;
	}

	updateGL();
}
void TrackComparisonOpenglWidget::TimeOut()
{

	updateGL();
}