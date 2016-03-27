#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>

#include "trackcomparisonpicture.h"
#include "tools.h"

TrackComparisonPicture::TrackComparisonPicture(QWidget *parent, QString filepath[4])
	: QMainWindow(parent)
{
	ui.setupUi(this);


	QLabel *label_ = new QLabel(this->statusBar());
	label_->setText("picture Viewer test 16/03/06");

	this->statusBar()->addWidget(label_);
	ui.label->setPixmap(QPixmap(filepath[0]));
	ui.label_2->setPixmap(QPixmap(filepath[1]));
	ui.label_3->setPixmap(QPixmap(filepath[2]));
	ui.label_4->setPixmap(QPixmap(filepath[3]));
	
}

TrackComparisonPicture::~TrackComparisonPicture()
{
}


