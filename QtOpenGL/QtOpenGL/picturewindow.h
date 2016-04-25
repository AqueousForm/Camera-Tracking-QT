#ifndef PICTUREWINDOW_H
#define PICTUREWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_pictureviewer.h"



class PictureWindow : public QMainWindow
{
	Q_OBJECT

public:
	PictureWindow(QWidget *parent = 0);
	~PictureWindow();

	public slots:
	void Open();
	void VisualizePictures();
private:
	Ui::PictureViewer ui;
	
	QString filepath_;
	
};

#endif // PICTUREWINDOW_H

