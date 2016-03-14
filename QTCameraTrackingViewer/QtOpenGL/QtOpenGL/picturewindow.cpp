#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>

#include "picturewindow.h"
#include "tools.h"

PictureWindow::PictureWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	

	QLabel *label_ = new QLabel(this->statusBar());
	label_->setText("picture Viewer test 16/03/06");

	this->statusBar()->addWidget(label_);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(Open()));
}

PictureWindow::~PictureWindow()
{
}

void PictureWindow::Open()
{
	filepath_ = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		"C:\\Users\\szh\\Desktop\\O_KF_TransformsTotal",
		tr("All Files(*.*)"));
	if (!filepath_.isEmpty())
	{
		VisualizePictures();
	}
	else
	{
		filepath_ = "";
	}
}
void PictureWindow::VisualizePictures(){
	ui.label->setPixmap(QPixmap(filepath_));

}