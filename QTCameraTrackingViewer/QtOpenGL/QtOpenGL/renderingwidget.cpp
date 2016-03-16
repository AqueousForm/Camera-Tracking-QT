
 #include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>

#include "renderingwidget.h"
#include "tools.h"
#include "ArcBall.h"

typedef trimesh::vec3  Vec3f;
using std::vector;

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

	automation_mode_ = true;
	disp_num_ = 0;

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimeOut()));
	timer->start(100);
}

RenderingWidget::~RenderingWidget()
{
	SAFEDELETE(ptr_arcball_);
}

void RenderingWidget::LoadTransFromFile(std::string file_path, bool automation_mode, bool is_no_trans, bool cube_mode)
{
	vec_matrix_.clear();
	disp_num_ = 0;

	std::string line;
	Eigen::MatrixXf RT(4, 4), RT_inv(4, 4);
	std::ifstream fin(file_path);
	if (!fin)
	{
		QMessageBox::warning(this, "Warning", "No such file!", 0, 1, 0);
	}

	vec_matrix_.push_back(Eigen::MatrixXf::Identity(4, 4));
	while (!fin.eof())
	{
		getline(fin, line, '#');
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				fin >> RT(j, k);

		if (is_no_trans)
		{
			RT(0, 3) = RT(1, 3) = RT(2, 3) = 0;
		}
		else
		{
			RT(0, 3) /= 20.0;
			RT(1, 3) /= 20.0;
			RT(2, 3) /= 20.0;
		}

		RT_inv = RT.inverse();
		vec_matrix_.push_back(RT_inv);
	}
	fin.close();

	automation_mode_ = automation_mode;
	cube_mode_ = cube_mode;
}
void RenderingWidget::Load3DPointFromFile(std::string file_path, bool view_3Dpoint_mode)
{
	
	vec_3DPoint_.clear();
	point_num_ = 0;

	Eigen::MatrixXf point_value(1, 6);
	std::ifstream fin(file_path);
	if (!fin)
	{
		QMessageBox::warning(this, "Warning", "No such file!", 0, 1, 0);
	}


	while (!fin.eof())
	{

		for (int j = 0; j < 6; j++){
			/*printf("123212321   %d\n", j);*/
			fin >> point_value(0, j);
		}
			


		point_value(0, 0) /= 20.0;
		point_value(0, 1) /= 20.0;
		point_value(0, 2) /= 20.0;
		point_value(0, 3) /= 255.0;
		point_value(0, 4) /= 255.0;
		point_value(0, 5) /= 255.0;
		point_num_++;
		vec_3DPoint_.push_back(point_value);
	}
	fin.close();

	view_3Dpoint_mode_ = view_3Dpoint_mode;
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
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1);
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

	if (cube_mode_)
		Render2();
	else
		Render();

	glPopMatrix();
}

void RenderingWidget::Render()
{
	if (vec_matrix_.size() == 0)
		return;
	//glColor3f(0.0, 0.0, 1.0);
	//glutWireTeapot(1);

	static int num = 0;

	//绘制一个点
	GLfloat p1, p2, p3;
	GLfloat x1, x2, x3;
	GLfloat y1, y2, y3;
	GLfloat z1, z2, z3;
	GLfloat a1, a2, a3;
	GLfloat b1, b2, b3;
	GLfloat c1, c2, c3;
	GLfloat d1, d2, d3;
	GLfloat e1, e2, e3;
	GLfloat f1, f2, f3;
	GLfloat g1, g2, g3;
	GLfloat h1, h2, h3;
	GLfloat pt1, pt2, pt3;
	GLfloat ptr, ptg, ptb;
	std::string line;
	Eigen::MatrixXf RT(4, 4), RTI(4, 4);

	int count = 0; // of little use

	for (size_t i = 0; i < disp_num_; ++i)
	{
		count++;
		//if (count > 200)
		//	continue;

		//if (count % 5 != 0)
		//	continue;

		Eigen::MatrixXf trans = vec_matrix_[i];
		trans.block<3, 1>(0, 3) = trans.block<3, 1>(0, 3)*scale;

		p1 = trans(0, 3);
		p2 = trans(1, 3);
		p3 = trans(2, 3);
		x1 = trans(0, 0) * axis_length + trans(0, 3);
		x2 = trans(1, 0) * axis_length + trans(1, 3);
		x3 = trans(2, 0) * axis_length + trans(2, 3);
		y1 = trans(0, 1) * axis_length + trans(0, 3);
		y2 = trans(1, 1) * axis_length + trans(1, 3);
		y3 = trans(2, 1) * axis_length + trans(2, 3);
		z1 = trans(0, 2) * axis_length + trans(0, 3);
		z2 = trans(1, 2) * axis_length + trans(1, 3);
		z3 = trans(2, 2) * axis_length + trans(2, 3);

		glColor3f(1.0f, 0.0f, 0.0f);
		glPointSize(6);//指定点的大小，9个像素单位
		glBegin(GL_POINTS);//开始画点
		glVertex3f(p1, p2, p3); // 在坐标为(0,0,0)的地方绘制了一个点
		glEnd();

		glColor3f(1.0f, 0.0f, 0.0f);//指定线的颜色,红色.X轴
		glBegin(GL_LINES);
		{
			glVertex3f(p1, p2, p3);
			glVertex3f(x1, x2, x3);

		}
		glEnd();

		glColor3f(0.0f, 1.0f, 0.0f);//指定线的颜色,绿色，y轴
		glBegin(GL_LINES);
		{
			glVertex3f(p1, p2, p3);
			glVertex3f(y1, y2, y3);
		}
		glEnd();

		glColor3f(0.0f, 0.0f, 1.0f);//指定线的颜色,蓝色，z轴
		glBegin(GL_LINES);
		glVertex3f(p1, p2, p3);
		glVertex3f(z1, z2, z3);
		glVertex3f(z1, z2, z3);
		glEnd();
	}
	
	if (view_3Dpoint_mode_){
		for (size_t i = 0; i < point_num_; ++i){
			Eigen::MatrixXf point3D = vec_3DPoint_[i];
			pt1 = point3D(0, 0);
			pt2 = point3D(0, 1);
			pt3 = point3D(0, 2);
			ptr = point3D(0, 3);
			ptg = point3D(0, 4);
			ptb = point3D(0, 5);
			printf("##################\n\n");
			glColor3f(ptr, ptg, ptb);
			glPointSize(4);//指定点的大小，9个像素单位
			glBegin(GL_POINTS);//开始画点
			glVertex3f(pt1, pt2, pt3); // 在坐标为(0,0,0)的地方绘制了一个点
			glEnd();

		}
	}
	else printf("**********************\n\n");
	//glutSwapBuffers();
}



void  RenderingWidget::Render2()
{


	if (vec_matrix_.size() == 0)
		return;
	//glColor3f(0.0, 0.0, 1.0);
	//glutWireTeapot(1);

	static int num = 0;

	//绘制一个点
	GLfloat p1, p2, p3;
	GLfloat x1, x2, x3;
	GLfloat y1, y2, y3;
	GLfloat z1, z2, z3;
	GLfloat a1, a2, a3;
	GLfloat b1, b2, b3;
	GLfloat c1, c2, c3;
	GLfloat d1, d2, d3;
	GLfloat e1, e2, e3;
	GLfloat f1, f2, f3;
	GLfloat g1, g2, g3;
	GLfloat h1, h2, h3;

	std::string line;
	Eigen::MatrixXf RT(4, 4), RTI(4, 4);

	// of little use


	//if (count > 200)
	//	continue;

	//if (count % 5 != 0)
	//	continue;


	int j = vec_matrix_.size();
	if (i > j - 2) i = 0;
	Eigen::MatrixXf trans = vec_matrix_[i++];
	trans.block<3, 1>(0, 3) = trans.block<3, 1>(0, 3)*scale;

	p1 = trans(0, 3);
	p2 = trans(1, 3);
	p3 = trans(2, 3);
	x1 = trans(0, 0) * axis_length + trans(0, 3);
	x2 = trans(1, 0) * axis_length + trans(1, 3);
	x3 = trans(2, 0) * axis_length + trans(2, 3);
	y1 = trans(0, 1) * axis_length + trans(0, 3);
	y2 = trans(1, 1) * axis_length + trans(1, 3);
	y3 = trans(2, 1) * axis_length + trans(2, 3);
	z1 = trans(0, 2) * axis_length + trans(0, 3);
	z2 = trans(1, 2) * axis_length + trans(1, 3);
	z3 = trans(2, 2) * axis_length + trans(2, 3);
	a1 = trans(0, 0) * b + trans(0, 1) * b - trans(0, 2) * b + trans(0, 3);
	a2 = trans(1, 0) * b + trans(1, 1) * b - trans(1, 2) * b + trans(1, 3);
	a3 = trans(2, 0) * b + trans(2, 1) * b - trans(2, 2) * b + trans(2, 3);

	b1 = -trans(0, 0) * b + trans(0, 1) * b - trans(0, 2) * b + trans(0, 3);
	b2 = -trans(1, 0) * b + trans(1, 1) * b - trans(1, 2) * b + trans(1, 3);
	b3 = -trans(2, 0) * b + trans(2, 1) * b - trans(2, 2) * b + trans(2, 3);

	c1 = -trans(0, 0) * b + trans(0, 1) * b + trans(0, 2) * b + trans(0, 3);
	c2 = -trans(1, 0) * b + trans(1, 1) * b + trans(1, 2) * b + trans(1, 3);
	c3 = -trans(2, 0) * b + trans(2, 1) * b + trans(2, 2) * b + trans(2, 3);

	d1 = trans(0, 0) * b + trans(0, 1) * b + trans(0, 2) * b + trans(0, 3);
	d2 = trans(1, 0) * b + trans(1, 1) * b + trans(1, 2) * b + trans(1, 3);
	d3 = trans(2, 0) * b + trans(2, 1) * b + trans(2, 2) * b + trans(2, 3);

	e1 = trans(0, 0) * b - trans(0, 1) * b + trans(0, 2) * b + trans(0, 3);
	e2 = trans(1, 0) * b - trans(1, 1) * b + trans(1, 2) * b + trans(1, 3);
	e3 = trans(2, 0) * b - trans(2, 1) * b + trans(2, 2) * b + trans(2, 3);

	f1 = -trans(0, 0) * b - trans(0, 1) * b + trans(0, 2) * b + trans(0, 3);
	f2 = -trans(1, 0) * b - trans(1, 1) * b + trans(1, 2) * b + trans(1, 3);
	f3 = -trans(2, 0) * b - trans(2, 1) * b + trans(2, 2) * b + trans(2, 3);

	g1 = -trans(0, 0) * b - trans(0, 1) * b - trans(0, 2) * b + trans(0, 3);
	g2 = -trans(1, 0) * b - trans(1, 1) * b - trans(1, 2) * b + trans(1, 3);
	g3 = -trans(2, 0) * b - trans(2, 1) * b - trans(2, 2) * b + trans(2, 3);

	h1 = trans(0, 0) * b - trans(0, 1) * b - trans(0, 2) * b + trans(0, 3);
	h2 = trans(1, 0) * b - trans(1, 1) * b - trans(1, 2) * b + trans(1, 3);
	h3 = trans(2, 0) * b - trans(2, 1) * b - trans(2, 2) * b + trans(2, 3);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(6);//指定点的大小，9个像素单位
	glBegin(GL_POINTS);//开始画点
	glVertex3f(p1, p2, p3); // 在坐标为(0,0,0)的地方绘制了一个点
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);//指定线的颜色,红色.X轴
	glBegin(GL_LINES);
	glVertex3f(p1, p2, p3);
	glVertex3f(x1, x2, x3);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);//指定线的颜色,绿色，y轴
	glBegin(GL_LINES);
	glVertex3f(p1, p2, p3);
	glVertex3f(y1, y2, y3);
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);//指定线的颜色,蓝色，z轴
	glBegin(GL_LINES);
	glVertex3f(p1, p2, p3);
	glVertex3f(z1, z2, z3);
	glVertex3f(z1, z2, z3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 0.0f);			// 颜色改成绿色
	glVertex3f(a1, a2, a3);			// 四边形的右上顶点 (顶面)
	glVertex3f(b1, b2, b3);			// 四边形的左上顶点 (顶面)
	glVertex3f(c1, c2, c3);			// 四边形的左下顶点 (顶面)
	glVertex3f(d1, d2, d3);			// 四边形的右下顶点 (顶面)


	glColor3f(0.0f, 0.5f, 0.0f);			// 颜色改成绿色
	glVertex3f(e1, e2, e3);			// 四边形的右上顶点(底面)
	glVertex3f(f1, f2, f3);			// 四边形的左上顶点(底面)
	glVertex3f(g1, g2, g3);			// 四边形的左下顶点(底面)
	glVertex3f(h1, h2, h3);			// 四边形的右下顶点(底面)

	glColor3f(0.5f, 0.0f, 0.0f);			// 颜色改成红色
	glVertex3f(d1, d2, d3);			// 四边形的右上顶点(前面)
	glVertex3f(c1, c2, c3);			// 四边形的左上顶点(前面)
	glVertex3f(f1, f2, f3);			// 四边形的左下顶点(前面)
	glVertex3f(e1, e2, e3);			// 四边形的右下顶点(前面)

	glColor3f(0.0f, 0.5f, 0.0f);			// 颜色改成绿色
	glVertex3f(h1, h2, h3);			// 四边形的右上顶点(后面)
	glVertex3f(g1, g2, g3);			// 四边形的左上顶点(后面)
	glVertex3f(b1, b2, b3);			// 四边形的左下顶点(后面)
	glVertex3f(a1, a2, a3);			// 四边形的右下顶点(后面)

	glColor3f(0.0f, 0.5f, 0.0f);			// 颜色改成绿色
	glVertex3f(c1, c2, c3);			// 四边形的右上顶点(左面)
	glVertex3f(b1, b2, b3);			// 四边形的左上顶点(左面)
	glVertex3f(g1, g2, g3);			// 四边形的左下顶点(左面)
	glVertex3f(f1, f2, f3);			// 四边形的右下顶点(左面)

	glColor3f(0.0f, 0.5f, 0.0f);			// 颜色改成绿色
	glVertex3f(a1, a2, a3);			// 四边形的右上顶点(右面)
	glVertex3f(d1, d2, d3);			// 四边形的左上顶点(右面)
	glVertex3f(e1, e2, e3);			// 四边形的左下顶点(右面)
	glVertex3f(h1, h2, h3);			// 四边形的右下顶点(右面)
	glEnd();


}

void RenderingWidget::TimeOut()
{
	int sz = vec_matrix_.size();
	if (!sz)
		return;

	if (automation_mode_)
		disp_num_ = (disp_num_ + 1) % sz;
	else
		disp_num_ = sz;
	updateGL();
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