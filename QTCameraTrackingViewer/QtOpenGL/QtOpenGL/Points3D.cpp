#include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>

#include "Points3D.h"
#include "tools.h"
#include "ArcBall.h"

using std::vector;

Points3D::Points3D()

{

}

void Points3D::Load3DPointFromFile(std::string file_path, bool view_3Dpoint_mode)
{

	vec_3DPoint_.clear();
	point_num_ = 0;

	Eigen::MatrixXf point_value(1, 6);
	std::ifstream fin(file_path);
	if (!fin)
	{
		/*QMessageBox::warning(this, "Warning", "No such file!", 0, 1, 0);*/
		printf("error!/n");
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

void Points3D::Draw3DPoints(){
	GLfloat pt1, pt2, pt3;
	GLfloat ptr, ptg, ptb;
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
}

