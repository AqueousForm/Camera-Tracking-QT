#ifndef TRACKCOMPARISONOPENGLWIDGET_H
#define TRACKCOMPARISONOPENGLWIDGET_H
#include <string>
#include <QGLWidget>
#include <QEvent>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Vec.h"
#include "renderingwidget.h"
#include "trajectory.h"
#include "trackcomparisonpicture.h"
using trimesh::vec;
using trimesh::point;
class CArcBall;
class QTimer;


class TrackComparisonOpenglWidget : public  RenderingWidget
{
	Q_OBJECT  //”√”⁄QTΩ‚Œˆ

public:
	TrackComparisonOpenglWidget(QWidget *parent, Trajectory * trajectory[10]);
	~TrackComparisonOpenglWidget();
	Trajectory *trajectory_[10];
	int num;
	void mousePressEvent(QMouseEvent *e);
	void FindThePoint(GLdouble posx, GLdouble posy, GLdouble posz);
	TrackComparisonPicture *picture_window_;
protected:
	virtual void Render();
	protected slots:
	virtual void TimeOut();
	

};
#endif //TRACKCOMPARISONOPENGLWIDGET_H