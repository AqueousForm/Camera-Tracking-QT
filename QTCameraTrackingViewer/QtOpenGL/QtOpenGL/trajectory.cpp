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

Trajectory::Trajectory(){
	frame_num_ = 0;
	total_num_ = 0;
}

Trajectory::~Trajectory(){

}

void Trajectory::LoadTransFromFile(std::string file_path, int num)
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
		getline(fin, line, '#');
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				fin >> RT(j, k);


		RT(0, 3) /= 20.0;
		RT(1, 3) /= 20.0;
		RT(2, 3) /= 20.0;


		RT_inv = RT.inverse();
		vec_matrix_.push_back(RT_inv);
	}
	fin.close();

	total_num_ = num;

	pr = get_rand()[0] / 10.0 * 7 + 0.3;
	pg = get_rand()[1] / 10.0 * 7 + 0.3;
	pb = get_rand()[2] / 10.0 * 7 + 0.3;
	lr = pr;
	lg = pg;
	lb = pb;


}
void Trajectory::DrawTrajectory(){
	if (vec_matrix_.size() == 0)
		return;
	

	static int num = 0;

	//����һ����
	GLfloat p1, p2, p3;
	GLfloat p4, p5, p6;

	std::string line;
	Eigen::MatrixXf RT(4, 4), RTI(4, 4);


	int sz = vec_matrix_.size();
	if (!sz)
		return;
	frame_num_ = sz;
	for (size_t i = 0; i < frame_num_; ++i)
	{

		Eigen::MatrixXf trans = vec_matrix_[i];
		trans.block<3, 1>(0, 3) = trans.block<3, 1>(0, 3)*scale;

		p1 = trans(0, 3);
		p2 = trans(1, 3);
		p3 = trans(2, 3);

		glColor3f(pr, pg, pb);
		glPointSize(8);//ָ����Ĵ�С��9�����ص�λ
		glBegin(GL_POINTS);//��ʼ����
		glVertex3f(p1, p2, p3); // ������Ϊ(0,0,0)�ĵط�������һ����
		glEnd();
		if (i != 0){
			//printf("%d  \n");
			Eigen::MatrixXf transpre = vec_matrix_[i - 1];
			transpre.block<3, 1>(0, 3) = transpre.block<3, 1>(0, 3)*scale;
			p4 = transpre(0, 3);
			p5 = transpre(1, 3);
			p6 = transpre(2, 3);
			glColor3f(lr, lg, lb);//ָ���ߵ���ɫ,��ɫ.X��
			glBegin(GL_LINES);
			{
				glVertex3f(p1, p2, p3);
				glVertex3f(p4, p5, p6);

			}
			glEnd();
		}

	}
}