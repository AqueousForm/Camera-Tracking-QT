#ifndef PICTURETRACKOPENGLWIDGET_H
#define PICTURETRACKOPENGLWIDGET_H
#include <string>
#include <QGLWidget>
#include <QEvent>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Vec.h"
#include "renderingwidget.h"
#include "frame.h"

using trimesh::vec;
using trimesh::point;
class CArcBall;
class QTimer;



class PictureTrackOpenglWidget : public  RenderingWidget
{
	Q_OBJECT  //”√”⁄QTΩ‚Œˆ

public:
	PictureTrackOpenglWidget(QWidget *parent, Frame **frame, QGraphicsView *graphicsView);
	~PictureTrackOpenglWidget();
	Frame **frame_1;
	QGraphicsView * graphicsView_1;
	
protected:
	virtual void Render();
	protected slots:
	virtual void TimeOut();
private:


};
#endif //TRACKCOMPARISONOPENGLWIDGET_H