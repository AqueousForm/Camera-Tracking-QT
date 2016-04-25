#include <iostream>
#include <fstream>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <gl/glut.h>
#include "picturetrackopenglwidget.h"
#include "tools.h"
#include "ArcBall.h"
#include <QGraphicsView>  
#include <QGraphicsScene> 
#include <QGraphicsPixmapItem>
#include <string>
using std::string;
using std::cout;
using std::endl;
using namespace std;
PictureTrackOpenglWidget::PictureTrackOpenglWidget(QWidget *parent, Frame **frame, QGraphicsView *graphicsView)
	: RenderingWidget(parent)
{
	ptr_arcball_ = new CArcBall(width(), height());

	eye_goal_[0] = 0.0;
	eye_goal_[1] = 0.0;
	eye_goal_[2] = 0.0;

	eye_direction_[0] = eye_direction_[1] = 0.0;
	eye_direction_[2] = 1.0;
	eye_distance_ = 15;
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimeOut()));
	timer->start(500);
	frame_1 = frame;
	graphicsView_1 = graphicsView;
	}

PictureTrackOpenglWidget::~PictureTrackOpenglWidget()
{
	SAFEDELETE(ptr_arcball_);
}



void PictureTrackOpenglWidget::Render()
{
	if ((*frame_1) != NULL){
	 (*frame_1)->DrawFrame();

	 char  string_frame_num[5];
	 string name_string_;
	 QString name_string;
	 int i;
	 const string str1 = "G:\\6\\harris\\O_TrackingData1\\FPimages";
	 const string str2 = "\\step";
	 const string str3_1 = "_img_with_FP_1.bmp";
	 
	 sprintf_s(string_frame_num, "%d", (*frame_1)->frame_num_+1);
	 
	 name_string_ = str1 + str2 + string_frame_num + str3_1;
	 QImage image(QString::fromStdString(name_string_));
	 cout << name_string_ << endl;
	 if (image.isNull())
	 {
		 QMessageBox::information(this, "Image Viewer", "Error Displaying image");
		 return;
	 }

	 QGraphicsScene* scene = new QGraphicsScene();
	 graphicsView_1->setScene(scene);
	 QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
	 scene->addItem(item);
	 graphicsView_1->show();
	 
	 
	}
	
}

void PictureTrackOpenglWidget::TimeOut()
{
	if (*frame_1 == NULL) return;
	if ((*frame_1)->automation_mode_)
		(*frame_1)->frame_num_ = ((*frame_1)->frame_num_ + 1) % ((*frame_1)->vec_matrix_.size() - 2);//here isssssssssssssssssssssssssssssssssssss a big problem sz should plus 1 ,but the size of the vector is wrong when data loading 
	else
		(*frame_1)->frame_num_ = (*frame_1)->vec_matrix_.size();
	if ((*frame_1)->frame_num_ == 0) (*frame_1)->frame_num_ = 1;
	updateGL();
}
