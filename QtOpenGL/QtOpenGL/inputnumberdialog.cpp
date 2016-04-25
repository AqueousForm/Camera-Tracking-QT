#include <QLabel>
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>

#include "inputnumberdialog.h"
#include "tools.h"

InputNumber::InputNumber(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(Accept()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(Reject()));
	number = 0;

}

InputNumber::~InputNumber()
{
}

void InputNumber::Accept()
{
	number = ui.lineEdit->text().toInt();

}

void InputNumber::Reject()
{
	
}