#ifndef FRAME_H
#define FRAME_H
#include <string>
#include <QGLWidget>
#include <QEvent>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Vec.h"

class Frame
{
	

public:
	Frame();
	~Frame();
	void LoadTransFromFile(std::string file_path, bool automation_mode, bool is_no_trans, bool cube_mode);
	void DrawFrame();
	void DrawCube();
	bool automation_mode_;
	bool cube_mode_;
	int frame_num_;
	std::vector<Eigen::MatrixXf> vec_matrix_;
public slots:

private:
	
	const float scale = 0.1;
	const float axis_length = 1;
	const GLfloat xRot = 0.0f;
	const GLfloat yRot = 0.0f;
	const GLfloat b = 0.5;
	size_t i = 0;
};
#endif 