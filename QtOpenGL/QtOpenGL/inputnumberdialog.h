#ifndef INPUTNUMBERDIALOG_H
#define INPUTNUMBERDIALOG_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_InputNumber.h"



class InputNumber : public QDialog
{
	Q_OBJECT

public:
	InputNumber(QWidget *parent = 0);
	~InputNumber();
	
	int number;
	public slots:
	void Accept();
	void Reject();
	
	
private:
	Ui::InputNumberDialog ui;

	
};

#endif // PICTUREWINDOW_H
