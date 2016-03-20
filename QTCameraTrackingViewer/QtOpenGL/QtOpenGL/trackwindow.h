#ifndef TRACKWINDOW_H
#define TRACKWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

#include "renderingwidget.h"
#include "frame.h"
#include "Points3D.h"
#include "ui_trackviewer.h"

class QLabel;
class TrackOpenglWidget;
class TrackWindow : public QMainWindow
{
	Q_OBJECT

public:
	TrackWindow(QWidget *parent = 0);
	~TrackWindow();

public slots:
	//void VisualizeFrame();
	void Open();
	//void Visualize3DPoint();
	void Open_3DPoint();
	void Get3DPointData();
	void GetFrameData();
	
public:
	Frame *frame_1;
	Points3D *point3d_1;
private:

	void CreateActions();

	Ui::trackviewer ui;
	RenderingWidget *ptr_glwidget_;
	TrackOpenglWidget *ptr_trackwidget_;
	
	QLabel *label_;


	QAction *automation_disp;
	QAction *complete_disp ;
	QAction *no_trans ;
	QAction *with_trans;
	QAction *cube_disp;
	QAction *with_3Dpoint,*no_3Dpoint;

	QString filepath_;
	QString filepath_3DPoint;
	
};

#endif //TRACKWINDOW_H
