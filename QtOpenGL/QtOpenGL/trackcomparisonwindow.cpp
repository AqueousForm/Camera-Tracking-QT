#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>
#include "trackcomparisonwindow.h"
#include "tools.h"
#include <iostream>
#include <fstream>
using namespace std;
TrackComparisonWindow::TrackComparisonWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	for (int i = 0; i < 10; i++){
		trajectory_[i] = new Trajectory();
	}

	//ptr_inputdialog = new InputNumber(this);
	//ptr_inputdialog->exec();
	//printf("%d\n", ptr_inputdialog->number);
	Open();
	
	ptr_trackwidget_ = new TrackComparisonOpenglWidget(this, trajectory_);
	ptr_glwidget_ = ptr_trackwidget_;

	ui.verticalLayout->addWidget(ptr_glwidget_);
	QLabel *label_ = new QLabel(this->statusBar());
	label_->setText("3D Viewer test 16/02/28");
	this->statusBar()->addWidget(label_);
	
}

TrackComparisonWindow::~TrackComparisonWindow()
{
}

// void TrackComparisonWindow::InputNum(){
// 
// }
void TrackComparisonWindow::Open()
{
	filepath = QFileDialog::getOpenFileNames(this,
			tr("Open File"),
		".\\O_KF_TransformsTotal",
		tr("Text Files(*.txt)"));
	tra_num = filepath.size();
	for (int i = 0; i < tra_num; i++){
		filepath_[i] = filepath[i];
		if (!filepath_[i].isEmpty())
		{
			GetFrameData(i, tra_num);
		}
		else
		{
			filepath_[i] = "";
		}
	}
}

void TrackComparisonWindow::GetFrameData(int i, int num)
{
	if (filepath_[i].isEmpty())
		return;
	int key_num = stringToNumber(filepath_[i].toStdString().c_str());
	//cout << key_num << endl;
	trajectory_[i]->LoadTransFromFile(filepath_[i].toStdString(), num,key_num);
}
 
//  
//  void TrackComparisonWindow::HightLight(){
//  
//  }

