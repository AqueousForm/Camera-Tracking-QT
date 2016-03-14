#ifndef RENDERINGWIDGET_H
#define RENDERINGWIDGET_H
#include <string>
#include <QGLWidget>
#include <QEvent>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Vec.h"

using trimesh::vec;
using trimesh::point;
class CArcBall;
class QTimer;

class RenderingWidget : public QGLWidget
{
	Q_OBJECT

public:
	RenderingWidget(QWidget *parent = 0);
	~RenderingWidget();
	// coordinate visualization
	void LoadTransFromFile(std::string file_path, bool automation_mode, bool is_no_trans,bool cube_mode);
	void Load3DPointFromFile(std::string file_path, bool view_3Dpoint_mode);
protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

	// mouse events
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void wheelEvent(QWheelEvent *e);

private slots:
	void TimeOut();
private:
	void Render();
	void Render2();

private:
	CArcBall *ptr_arcball_;
	QTimer *timer;
	// eye
	GLfloat	eye_distance_;
	point eye_goal_;
	vec	eye_direction_;
	QPoint current_position_;

	// coordinate visualization
	std::vector<Eigen::MatrixXf> vec_matrix_;
	std::vector<Eigen::MatrixXf> vec_3DPoint_;
	const float scale = 0.1;
	const float axis_length = 1;
	const GLfloat xRot = 0.0f;
	const GLfloat yRot = 0.0f;
	const GLfloat b = 0.5;
	bool automation_mode_;
	bool cube_mode_;
	bool view_3Dpoint_mode_;
	int disp_num_;
	int point_num_;
	size_t i = 0;
};

#endif // RENDERINGWIDGET_H
