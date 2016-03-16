#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>

#include "MyMainWindow.h"
#include "tools.h"

MyMainWindow::MyMainWindow(QWidget *parent)
	: QMainWindow(parent), picture_window_(NULL), opengl_window_(NULL)
{
	ui.setupUi(this);
	QLabel *label_ = new QLabel(this->statusBar());
	label_->setText("3D Viewer test 16/02/28");
	this->statusBar()->addWidget(label_);
	connect(ui.actionStart_2, SIGNAL(triggered()), this, SLOT(ChangeToPictureWindow()));
	connect(ui.actionStart, SIGNAL(triggered()), this, SLOT(ChangeToOpenglWindow()));
}

MyMainWindow::~MyMainWindow()
{
}

void MyMainWindow::ChangeToPictureWindow()
{
	//SAFEDELETE(picture_window_);
	picture_window_ = new PictureWindow(this);
	picture_window_->show();
	//this->hide();
}
void MyMainWindow::ChangeToOpenglWindow()
{
	//SAFEDELETE(opengl_window_);
	opengl_window_ = new TrackWindow(this);
	opengl_window_->show();
	//this->hide();
}

