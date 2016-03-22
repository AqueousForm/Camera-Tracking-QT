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
	virtual void Render();
	
	//virtual void Render2();
protected slots:
	virtual void TimeOut();

	

protected:
	CArcBall *ptr_arcball_;
	QTimer *timer;
	// eye
	GLfloat	eye_distance_;
	point eye_goal_;
	vec	eye_direction_;
	QPoint current_position_;


};

#endif // RENDERINGWIDGET_H
