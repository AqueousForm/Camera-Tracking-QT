#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_mainwindow.h"
#include "picturewindow.h"
#include "trackwindow.h"
#include "trackcomparisonwindow.h"
#include "picturetrackwindow.h"


class MyMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MyMainWindow(QWidget *parent = 0);
	~MyMainWindow();

public slots:
 	void ChangeToPictureWindow();
	void ChangeToTrackWindow();
	void ChangeToTrackComparisonWindow();
	void ChangeToPictureTrackWindow();
private:


	Ui::MainWindow ui;
 	PictureWindow *picture_window_;
	TrackWindow *track_window_;
	TrackComparisonWindow *track_comparison_window_;
	PictureTrackWindow *picture_track_window_;
};

#endif //MYMAINWINDOW_H
