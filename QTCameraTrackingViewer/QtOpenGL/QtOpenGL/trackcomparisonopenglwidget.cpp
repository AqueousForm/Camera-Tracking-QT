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
	for (int j = 0; j < 10; j++){
		trajectory_[j] = trajectory[j];
	}
	int size = trajectory_[0]->vec_matrix_.size();
	eye_goal_[0] = (trajectory_[0]->vec_matrix_[0](0, 3) + trajectory_[0]->vec_matrix_[size - 2](0, 3)) / 2;
	eye_goal_[1] = (trajectory_[0]->vec_matrix_[0](1, 3) + trajectory_[0]->vec_matrix_[size - 2](1, 3)) / 2;
	eye_goal_[2] = (trajectory_[0]->vec_matrix_[0](2, 3) + trajectory_[0]->vec_matrix_[size - 2](2, 3)) / 2;

	eye_distance_ = 1500;

	eye_direction_[0] = 0;
	eye_direction_[1] = 0;
	eye_direction_[2] = 1;


	//cout << eye_direction_[0] <<"   "<< eye_direction_[1] <<"    "<< eye_direction_[2] << endl;
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

	if (1){
		int k = 0;
		int p = 0;
		int i;
		for (i = 0; i < num; i++){
			if (trajectory_[i]->key_num_ == 1){
				k = i;

			}
			//cout << k << trajectory_[i]->key_num_ << num << endl;
		}

		for (i = 0; i < num; i++){
			if (i == k)continue;
			int sz = trajectory_[i]->vec_matrix_.size();
			GLfloat x1 = trajectory_[i]->vec_matrix_[sz - 1](1, 3);
			//cout << sz << "   " << trajectory_[k]->vec_matrix_.size() << "    " << x1 << endl;

			GLfloat *det_ = new GLfloat[sz];//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			GLfloat *det_det = new GLfloat[sz];
			GLfloat det_det_sum;
			for (int j = 0; j < sz - 1; j++){
				det_[j] = 0;
				det_det[j] = 0;
			}
			GLfloat a1, a2, a3;
			GLfloat b1, b2, b3;
			for (int m = 0; m < sz - 1; m++){
				a1 = trajectory_[i]->vec_matrix_[m](0, 3);
				a2 = trajectory_[i]->vec_matrix_[m](1, 3);
				a3 = trajectory_[i]->vec_matrix_[m](2, 3);

				b1 = trajectory_[k]->vec_matrix_[m * trajectory_[i]->key_num_](0, 3);
				b2 = trajectory_[k]->vec_matrix_[m * trajectory_[i]->key_num_](1, 3);
				b3 = trajectory_[k]->vec_matrix_[m * trajectory_[i]->key_num_](2, 3);
				det_[m] = sqrt((a1 - b1)*(a1 - b1) + (a2 - b2)*(a2 - b2) + (a3 - b3)*(a3 - b3));

			}

			for (int m = 1; m < sz - 1; m++){

				det_det[m] = abs(det_[m] - det_[m - 1]);
				det_det_sum += det_det[m];
				//printf("%f \n",det_det[m]);
			}
			det_det_sum = det_det_sum / sz;
			//printf("%f\n", det_det_sum);
			for (int m = 1; m < sz - 1; m++){
				if (det_det[m] / det_det_sum > 1.2){
					//		printf("%d@@@@@@@@@@@@@@@@@\n", m);
					GLfloat p1, p2, p3;
					p1 = trajectory_[i]->vec_matrix_[m](0, 3);
					p2 = trajectory_[i]->vec_matrix_[m](1, 3);
					p3 = trajectory_[i]->vec_matrix_[m](2, 3);
					glColor3f(1, 1, 1);
					glPointSize(12);//指定点的大小，9个像素单位
					glBegin(GL_POINTS);//开始画点
					glVertex3f(p1, p2, p3); // 在坐标为(0,0,0)的地方绘制了一个点
					glEnd();
				}
			}
		}
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
		//cout << lastPos.x() << ' ' << lastPos.y() << ' ' << winx << ' ' << winy << ' ' << posx << ' ' << posy << ' ' << posz << endl;
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

			if (sqrt(a + b + c) / sqrt(p1*p1 + p2*p2 + p3*p3) < key){
				total_num = i + 1;
				vector_num = j + 1;
				key = sqrt(a + b + c) / sqrt(p1*p1 + p2*p2 + p3*p3);
				//printf("find the point %d  %d  %lf\n\n", total_num, vector_num, key);
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
		sprintf_s(string_total_num, "%d", total_num);
		sprintf_s(string_vector_num, "%d", vector_num + 1);

		name_string_[0] = str1 + string_total_num + str2 + string_vector_num + str3_1;
		name_string_[1] = str1 + string_total_num + str2 + string_vector_num + str3_2;
		name_string_[2] = str1 + string_total_num + str2 + string_vector_num + str3_3;
		name_string_[3] = str1 + string_total_num + str2 + string_vector_num + str3_4;

		name_string[0] = QString::fromStdString(name_string_[0]);
		name_string[1] = QString::fromStdString(name_string_[1]);
		name_string[2] = QString::fromStdString(name_string_[2]);
		name_string[3] = QString::fromStdString(name_string_[3]);
		//cout << name_string_[3] << endl;
		picture_window_ = new TrackComparisonPicture(this, name_string);
		picture_window_->show();

	}
}