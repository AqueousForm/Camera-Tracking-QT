#include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>

#include "renderingwidget.h"
#include "tools.h"
#include "ArcBall.h"

//typedef trimesh::vec3  Vec3f;
using std::vector;
using  namespace std;
RenderingWidget::RenderingWidget(QWidget *parent)
	: QGLWidget(parent)
{
	ptr_arcball_ = new CArcBall(width(), height());

	eye_goal_[0] = 0.0;
	eye_goal_[1] = 0.0;
	eye_goal_[2] = 0.0;

	eye_direction_[0] = eye_direction_[1] = 0.0;
	eye_direction_[2] = 1.0;

	eye_distance_ = 15;
	// 
	// 	automation_mode_ = true;
	// 	disp_num_ = 0;

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimeOut()));
	timer->start(100);
}

RenderingWidget::~RenderingWidget()
{
	SAFEDELETE(ptr_arcball_);
}

void RenderingWidget::initializeGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_DOUBLEBUFFER);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);        //  设置深度测试类型
	
}

void RenderingWidget::resizeGL(int w, int h)
{
	h = (h == 0) ? 1 : h;

	ptr_arcball_->reSetBound(w, h);

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, GLdouble(w) / GLdouble(h), 0.001, 5000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	updateGL();
}

void RenderingWidget::paintGL()
{
	glShadeModel(GL_SMOOTH);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	register vec eyepos = eye_distance_*eye_direction_;
	gluLookAt(eyepos[0], eyepos[1], eyepos[2], eye_goal_[0], eye_goal_[1], eye_goal_[2], 0.0, 1.0, 0.0);

	glPushMatrix();
	glMultMatrixf(ptr_arcball_->GetBallMatrix());

	Render();

	glPopMatrix();
}

void RenderingWidget::Render()
{

}



void RenderingWidget::TimeOut()
{

}

void RenderingWidget::mousePressEvent(QMouseEvent *e)
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
// 	if (e->buttons()&Qt::RightButton)//鼠标右键
// 	{
// 		GLfloat px;
// 		GLfloat py;
// 		GLfloat winx;
// 		GLfloat winy;
// 		GLfloat winz;
// 		GLdouble posx, posy, posz;
// 		QPoint lastPos;
// 		lastPos = e->pos();
// 		px = lastPos.x();
// 		py = lastPos.y();
// 		GLint viewport[4];
// 		GLdouble mvmatrix[16], projmatrix[16];
// 		glPushMatrix();
// 		glMultMatrixf(ptr_arcball_->GetBallMatrix());
// 		//glRotatef(-30.0, 0.0, 0.0, 1.0);//之前绘图时进行的旋转
// 		glGetIntegerv(GL_VIEWPORT, viewport);
// 		glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
// 		glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
// 		glPopMatrix();
// 		winx = px;
// 		winy = (float)viewport[3] - py;//windows下y值机制和opengl中不一样
// 		glReadPixels((int)winx, (int)winy, 1, 1,
// 			GL_DEPTH_COMPONENT, GL_FLOAT, &winz);//从帧缓冲区读取鼠标点深度信息
// 		gluUnProject((GLdouble)winx, (GLdouble)winy,
// 			(GLdouble)winz, mvmatrix, projmatrix, viewport, &posx, &posy, &posz);
// 		cout << lastPos.x() << ' ' << lastPos.y() << ' ' << winx << ' ' << winy << ' ' << posx << ' ' << posy << ' ' << posz << endl;
// 	}

	updateGL();
}

void RenderingWidget::mouseMoveEvent(QMouseEvent *e)
{
	switch (e->buttons())
	{
		setCursor(Qt::ClosedHandCursor);
	case Qt::LeftButton:
		ptr_arcball_->MouseMove(e->pos());
		break;
	case Qt::MidButton:
		eye_goal_[0] -= 4.0*GLfloat(e->x() - current_position_.x()) / GLfloat(width());
		eye_goal_[1] += 4.0*GLfloat(e->y() - current_position_.y()) / GLfloat(height());
		current_position_ = e->pos();
		break;
	default:
		break;
	}

	updateGL();
}

void RenderingWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
	switch (e->button())
	{
	case Qt::LeftButton:
		break;
	default:
		break;
	}
	updateGL();
}

void RenderingWidget::mouseReleaseEvent(QMouseEvent *e)
{
	switch (e->button())
	{
	case Qt::LeftButton:
		ptr_arcball_->MouseUp(e->pos());
		setCursor(Qt::ArrowCursor);
		break;
	case Qt::RightButton:
		break;
	default:
		break;
	}
}

void RenderingWidget::wheelEvent(QWheelEvent *e)
{
	eye_distance_ += e->delta()*0.001;
	eye_distance_ = eye_distance_ < 0 ? 0 : eye_distance_;

	updateGL();
}
// 
// void RenderingWidget::screen2GLPoint()
// {
// 	int x = xCord;              /* 屏幕坐标 */
// 	int y = yCord;
// 	GLint viewport[4];
// 	GLdouble mvmatrix[16], projmatrix[16];
// 	GLfloat winx, winy, winz;
// 	GLdouble posx, posy, posz;
// 
// 	glPushMatrix();
// 
// 	//glScalef(0.1, 0.1, 0.1);  
// 	glGetIntegerv(GL_VIEWPORT, viewport);           /* 获取三个矩阵 */
// 	glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
// 	glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
// 
// 	glPopMatrix();
// 
// 	winx = x;
// 	winy = 100 - y;
// 
// 	glReadPixels((int)winx, (int)winy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winz);          /* 获取深度 */
// 	gluUnProject(winx, winy, winz, mvmatrix, projmatrix, viewport, &posx, &posy, &posz);    /* 获取三维坐标 */
// 	cout << posx << ' ' << posy << ' ' << posz << endl;
// }

