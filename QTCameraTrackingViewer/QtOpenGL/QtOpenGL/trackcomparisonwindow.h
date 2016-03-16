#ifndef TRACKCOMPARISONWINDOW_H
#define TRACKCOMPARISONWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "renderingwidget.h"
#include "ui_trackcomparisonviewer.h"

class QLabel;

class TrackComparisonWindow : public QMainWindow
{
	Q_OBJECT

public:
	TrackComparisonWindow(QWidget *parent = 0);
	~TrackComparisonWindow();

	public slots:
	void VisualizeFrame();
	void Open();




private:

	void CreateActions();

	Ui::trackcomparisonviewer ui;
	RenderingWidget *ptr_glwidget_;

	QLabel *label_;

	QAction *automation_disp;
	QAction *complete_disp;
	QAction *no_trans;
	QAction *with_trans;
	QAction *cube_disp;
	QAction *with_3Dpoint, *no_3Dpoint;

	QString filepath_;
	QString filepath_3DPoint;

};

#endif //TRACKWINDOW_H
