#ifndef POINTS3D_H
#define POINTS3D_H
#include <string>
#include <QGLWidget>
#include <QEvent>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Vec.h"

class Points3D
{


public:
	Points3D();
	~Points3D();
	void Load3DPointFromFile(std::string file_path, bool view_3Dpoint_mode);
	void Draw3DPoints();
	bool view_3Dpoint_mode_;
	int point_num_;
public slots:

private:
	std::vector<Eigen::MatrixXf> vec_3DPoint_;
	const float scale = 0.1;
	const float axis_length = 1;
	const GLfloat xRot = 0.0f;
	const GLfloat yRot = 0.0f;
	const GLfloat b = 0.5;

	size_t i = 0;
};
#endif 