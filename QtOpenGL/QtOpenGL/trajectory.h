#ifndef TRAJECTORY_H
#define TRAJECTORY_H
#include <string>
#include <QGLWidget>
#include <QEvent>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Vec.h"

class Trajectory
{


public:
	Trajectory();
	~Trajectory();
	void LoadTransFromFile(std::string file_path, int total_num,int key_num);
	void DrawTrajectory();
	int frame_num_;
	int total_num_;
	int key_num_;
	
	//int highlight_mode_;
	public slots:
	std::vector<Eigen::MatrixXf> vec_matrix_;
private:
	
	const float scale = 1;
	const float axis_length = 1;
	const GLfloat xRot = 0.0f;
	const GLfloat yRot = 0.0f;
	const GLfloat b = 0.5;
	size_t i = 0;
	float pr, pg, pb, lr, lg, lb;
};
#endif 