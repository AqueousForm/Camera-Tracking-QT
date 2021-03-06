#include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>

#include "trajectory.h"
#include "tools.h"
#include "ArcBall.h"

using std::vector;
using std::cout;
using std::endl;
Trajectory::Trajectory(){
	frame_num_ = 0;
	total_num_ = 0;
}

Trajectory::~Trajectory(){

}

void Trajectory::LoadTransFromFile(std::string file_path, int total_num,int key_num)
{
	vec_matrix_.clear();
	std::string line;
	Eigen::MatrixXf RT(4, 4), RT_inv(4, 4);
	std::ifstream fin(file_path);

	if (!fin)
	{
		/*QMessageBox::warning(this, "Warning", "No such file!", 0, 1, 0);*/
		printf("error!/n");
	}

	vec_matrix_.push_back(Eigen::MatrixXf::Identity(4, 4));

	while (!fin.eof())
	{
		//getline(fin, line, '#');
		char c;
		fin >> c;
		while (!isdigit(c)&&c!='-'&&c!=EOF){
			getline(fin, line, '#');
			fin >> c;
						
		}
		if (fin.eof()) 
			break;
		fin.putback(c);
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				fin >> RT(j, k);
		//cout << RT(0, 3) << endl;
		// 
		// 		RT(0, 3) /= 20.0;
		// 		RT(1, 3) /= 20.0;
		// 		RT(2, 3) /= 20.0;


		RT_inv = RT.inverse();
		vec_matrix_.push_back(RT_inv);
	}

	fin.close();

	total_num_ = total_num;
	float *rgb = get_rand();
	//cout << rgb[0] << "   !@# " << rgb[1] << "   !@# "<<rgb[2] << endl;
	float test = rgb[0] / 10.0 * 8.0;
	//cout << test <<"##########"<< endl;
	pr = rgb[0] / 10.0 * 8.0 + 0.2;
	pg = rgb[1] / 10.0 * 8.0 + 0.2;
	pb = rgb[2] / 10.0 * 8.0 + 0.2;
	lr = pr;
	lg = pg;
	lb = pb;

	//cout << pr << "  " << pg << "  " << pb << "  " << endl;
	key_num_ = key_num;
	//hight_mode_ = hight_mode;

}
void Trajectory::DrawTrajectory(){
	if (vec_matrix_.size() == 0)
		return;
	
	GLfloat det_sum = 0;
	GLfloat det_1 = 0;
	int sz = vec_matrix_.size();
// 	if (hight_mode_){

 		/*for (int m = 1; m < sz; m++){
 			a1 = vec_matrix_[m](0, 3);
 			a2 = vec_matrix_[m](1, 3);
 			a3 = vec_matrix_[m](2, 3);
 
 			b1 = vec_matrix_[m - 1](0, 3);
 			b2 = vec_matrix_[m - 1](1, 3);
 			b3 = vec_matrix_[m - 1](2, 3);
 			det_sum += sqrt((a1 - b1)*(a1 - b1) + (a2 - b2)*(a2 - b2) + (a3 - b3)*(a3 - b3));
 
 		}
 		det_sum = det_sum / sz;
 
 		for (int m = 1; m < sz; m++){
 			a1 = vec_matrix_[m](0, 3);
 			a2 = vec_matrix_[m](1, 3);
 			a3 = vec_matrix_[m](2, 3);
 
 			b1 = vec_matrix_[m - 1](0, 3);
 			b2 = vec_matrix_[m - 1](1, 3);
 			b3 = vec_matrix_[m - 1](2, 3);
 			det_1 = sqrt((a1 - b1)*(a1 - b1) + (a2 - b2)*(a2 - b2) + (a3 - b3)*(a3 - b3));
 			if (det_1>det_sum)
 
 		}
 	}*/

	//static int num = 0; ???????????

	//绘制一个点
	GLfloat p1, p2, p3;
	GLfloat p4, p5, p6;

	std::string line;
	Eigen::MatrixXf RT(4, 4), RTI(4, 4);


	frame_num_ = sz;
	for (size_t i = 0; i < frame_num_; ++i)
	{

		Eigen::MatrixXf trans = vec_matrix_[i];
		trans.block<3, 1>(0, 3) = trans.block<3, 1>(0, 3)*scale;

		p1 = trans(0, 3);
		p2 = trans(1, 3);
		p3 = trans(2, 3);

		glColor3f(pr, pg, pb);
		glPointSize(6);//指定点的大小，9个像素单位
		glBegin(GL_POINTS);//开始画点
		glVertex3f(p1, p2, p3); // 在坐标为(0,0,0)的地方绘制了一个点
		glEnd();
		if (i != 0){
			//printf("%d  \n");
			Eigen::MatrixXf transpre = vec_matrix_[i - 1];
			transpre.block<3, 1>(0, 3) = transpre.block<3, 1>(0, 3)*scale;
			p4 = transpre(0, 3);
			p5 = transpre(1, 3);
			p6 = transpre(2, 3);
			glColor3f(lr, lg, lb);//指定线的颜色,红色.X轴
			glBegin(GL_LINES);
			{
				glVertex3f(p1, p2, p3);
				glVertex3f(p4, p5, p6);

			}
			glEnd();
		}

	}
}