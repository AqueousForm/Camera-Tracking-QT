#include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>
#include "trackcomparisonopenglwidget.h"
#include "tools.h"
#include "ArcBall.h"
#include "math.h"
#include "trackcomparisonpicture.h"


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

	eye_distance_ = 40;
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
		FindThePoint(posx, posy, posz);
	}

	updateGL();
}
void TrackComparisonOpenglWidget::TimeOut()
{

	updateGL();
}

void TrackComparisonOpenglWidget::FindThePoint(GLdouble posx, GLdouble posy, GLdouble posz)
{
	int total_num = 0;
	int vector_num = 0;
	num = trajectory_[0]->total_num_;
	double key = 0.1;
	for (int i = 0; i < num; i++){
		int tra_size = trajectory_[i]->vec_matrix_.size();
		for (int j = 0; j < tra_size; j++){
			Eigen::MatrixXf trans = trajectory_[i]->vec_matrix_[j];
			GLdouble p1, p2, p3;
			p1 = trans(0, 3);
			p2 = trans(1, 3);
			p3 = trans(2, 3);
			double a = (p1 - posx)*(p1 - posx);
			double b = (p2 - posy)*(p2 - posy);
			double c = (p3 - posz)*(p3 - posz);
			//printf("a  b  c %lf  %lf   %lf \n", a, b, c);
			
			if (sqrt(a + b + c)/sqrt(p1*p1+p2*p2+p3*p3) <key ){
				total_num = i + 1;
				vector_num = j + 1;
				key = sqrt(a + b + c) / sqrt(p1*p1 + p2*p2 + p3*p3);
				printf("find the point %d  %d  %lf\n\n", total_num, vector_num, key);
			}
		}

	}

	if ((total_num != 0) && (vector_num != 0)){

		char  string_total_num[5], string_vector_num[5];
		string name_string_[4];
		QString name_string[4];
		const string str1 = ".\\Pictures\\FPimages_";
		const string str2 = "\\step";
		const string str3_1 = "_img_with_FP_1.bmp";
		const string str3_2 = "_img_with_FP_2.bmp";
		const string str3_3 = "_img_with_FP_3.bmp";
		const string str3_4 = "_img_with_FP_4.bmp";
		sprintf_s(string_total_num, "%d", total_num );
		sprintf_s(string_vector_num, "%d", vector_num + 1);
		
		name_string_[0] = str1 + string_total_num + str2 + string_vector_num + str3_1;
		name_string_[1] = str1 + string_total_num + str2 + string_vector_num + str3_2;
		name_string_[2] = str1 + string_total_num + str2 + string_vector_num + str3_3;
		name_string_[3] = str1 + string_total_num + str2 + string_vector_num + str3_4;
		
		name_string[0] = QString::fromStdString(name_string_[0]);
		name_string[1] = QString::fromStdString(name_string_[1]);
		name_string[2] = QString::fromStdString(name_string_[2]);
		name_string[3] = QString::fromStdString(name_string_[3]);
		cout<< name_string_[3]<<endl;
		picture_window_ = new TrackComparisonPicture(this,name_string);
		picture_window_->show();

	}
}