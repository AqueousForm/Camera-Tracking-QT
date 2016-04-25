#ifndef PICTURETRACKWINDOW_H
#define PICTURETRACKWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

#include "renderingwidget.h"
#include "frame.h"
#include "ui_picture and track viewer.h"

class QLabel;
class PictureTrackOpenglWidget;
class PictureTrackWindow : public QMainWindow
{
	Q_OBJECT

public:
	PictureTrackWindow(QWidget *parent = 0);
	~PictureTrackWindow();
	
	int total_num;
	public slots:
	void Open();
	void GetFrameData();

public:
	Frame *frame_1;


private:
	void Get3DPointData(Eigen::MatrixXf RT, int i);
	

	Ui::picturetrackwindow ui;
	RenderingWidget *ptr_glwidget_;
	PictureTrackOpenglWidget *ptr_picturetrackwidget_;
 
// 	QAction *automation_disp;
// 	QAction *complete_disp;
// 	QAction *no_trans;
// 	QAction *with_trans;
// 	QAction *cube_disp;
// 	QAction *with_3Dpoint, *no_3Dpoint;

	QString filepath_;
// 	QString filepath_transform;
// 	QStringList filepath_3DPoint;

};

#endif 
