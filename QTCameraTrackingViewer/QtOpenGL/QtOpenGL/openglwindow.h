#ifndef QTOPENGLWINDOW_H
#define QTOPENGLWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>

#include "renderingwidget.h"
#include "ui_openglviewer.h"

class QLabel;

class OpenglWindow : public QMainWindow
{
	Q_OBJECT

public:
	OpenglWindow(QWidget *parent = 0);
	~OpenglWindow();

	public slots:
	void VisualizeFrame();
	/*void VisualizeFrame_1();*/
	void Open();
	/*void Open_1();*/
	void Visualize3DPoint();
	//void Visualize3DPoint_1();
	void Open_3DPoint();
	


private:

	void CreateActions();

	Ui::openglviewer ui;
	RenderingWidget *ptr_glwidget_;
	
	QLabel *label_;

	QAction *automation_disp;
	QAction *complete_disp ;
	QAction *no_trans ;
	QAction *with_trans;
	QAction *cube_disp;
	QAction *with_3Dpoint,*no_3Dpoint;

	QString filepath_;
	QString filepath_3DPoint;
	
};

#endif // QTOPENGLWINDOW_H
