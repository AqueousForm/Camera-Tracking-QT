#ifndef TRACKOPENGLWIDGET_H
#define TRACKOPENGLWIDGET_H
#include <string>
#include <QGLWidget>
#include <QEvent>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Vec.h"
#include "renderingwidget.h"
#include "frame.h"
#include "Points3D.h"
using trimesh::vec;
using trimesh::point;
class CArcBall;
class QTimer;



class TrackOpenglWidget : public  RenderingWidget
{
	Q_OBJECT  //”√”⁄QTΩ‚Œˆ

public:
	TrackOpenglWidget(QWidget *parent , Frame **frame, Points3D  ***point);
	~TrackOpenglWidget();
	Frame **frame_1;
	Points3D  ***points3d_;
	int pointsize;
protected :
	virtual void Render();
protected slots:
	virtual void TimeOut();
private :
	
	
};
#endif //TRACKCOMPARISONOPENGLWIDGET_H