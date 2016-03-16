#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_mainwindow.h"
#include "picturewindow.h"
#include "trackwindow.h"
class QLabel;

class MyMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MyMainWindow(QWidget *parent = 0);
	~MyMainWindow();

public slots:
 	void ChangeToPictureWindow();
	void ChangeToOpenglWindow();
private:


	Ui::MainWindow ui;
 	PictureWindow *picture_window_;
	TrackWindow *opengl_window_;
};

#endif //MYMAINWINDOW_H
