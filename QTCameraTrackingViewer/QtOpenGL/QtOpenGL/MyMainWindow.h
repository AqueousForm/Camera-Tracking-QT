#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

/*#include "renderingwidget.h"*/
#include "ui_mainwindow.h"
#include "picturewindow.h"
#include "openglwindow.h"
class QLabel;

class MyMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MyMainWindow(QWidget *parent = 0);
	~MyMainWindow();

public slots:
// 	void VisualizeFrame();
// 	void VisualizeFrame_1();
// 	void Open();
// 	void Open_1();
// 	void Visualize3DPoint();
// 	//void Visualize3DPoint_1();
// 	void Open_3DPoint();
 	void ChangeToPictureWindow();
	void ChangeToOpenglWindow();
// 	//void Open_3DPoint_1();

private:

// 	void CreateActions();
// 	void CreateActions_1();
	Ui::MainWindow ui;
// 	RenderingWidget *ptr_glwidget_,*ptr_glwidget_1;
// 	QHBoxLayout *vbox_layout_, *vbox_layout_1;
// 	QLabel *label_;
// 
// 	QAction *automation_disp,*automation_disp_1;
// 	QAction *complete_disp, *complete_disp_1;
// 	QAction *no_trans, *no_trans_1;
// 	QAction *with_trans, *with_trans_1;
// 	QAction *cube_disp, *cube_disp_1;
// 	QAction *with_3Dpoint, *no_3Dpoint;
// 
// 	QString filepath_,filepath_1;
// 	QString filepath_3DPoint, filepath_3DPoint_1;
 	PictureWindow *picture_window_;
	OpenglWindow *opengl_window_;
};

#endif //MYMAINWINDOW_H
