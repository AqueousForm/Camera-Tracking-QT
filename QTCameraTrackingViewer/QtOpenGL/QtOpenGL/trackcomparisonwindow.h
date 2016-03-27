#ifndef TRACKCOMPARISONWINDOW_H
#define TRACKCOMPARISONWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_trackcomparisonviewer.h"
#include "trackcomparisonopenglwidget.h"
#include "trajectory.h"
#include "inputnumberdialog.h"
class QLabel;

class TrackComparisonWindow : public QMainWindow
{
	Q_OBJECT

public:
	TrackComparisonWindow(QWidget *parent = 0);
	~TrackComparisonWindow();
	Trajectory *trajectory_[10];
	int tra_num;
	public slots:
	// 	
	void GetFrameData(int i, int n);

	void Open();
	/*void InputNum();*/
	//void HightLight();


private:

	

	Ui::trackcomparisonviewer ui;
	RenderingWidget *ptr_glwidget_;

	TrackComparisonOpenglWidget *ptr_trackwidget_;
	// 	QLabel *label_;
	// 
	QStringList filepath; 
	QString filepath_[10];
	InputNumber *ptr_inputdialog;
	// 	QString filepath_3DPoint;

};

#endif //TRACKCOMPARISONWINDOW_H
