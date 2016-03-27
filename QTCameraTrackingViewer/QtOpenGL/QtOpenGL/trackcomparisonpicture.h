#ifndef TRACKCOMPARISONPICTURE_H
#define TRACKCOMPARISONPICTURE_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_trackcomparisonpicturewindow.h"



class TrackComparisonPicture : public QMainWindow
{
	Q_OBJECT

public:
	TrackComparisonPicture(QWidget *parent, QString filepath[4]);
	~TrackComparisonPicture();

	public slots:
	
private:
	Ui::trackcomparisonpicturewindow ui;

	
};

#endif 

