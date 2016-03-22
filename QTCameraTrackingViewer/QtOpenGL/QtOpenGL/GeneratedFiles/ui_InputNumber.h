/********************************************************************************
** Form generated from reading UI file 'InputNumber.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTNUMBER_H
#define UI_INPUTNUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_InputNumberDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *InputNumberDialog)
    {
        if (InputNumberDialog->objectName().isEmpty())
            InputNumberDialog->setObjectName(QStringLiteral("InputNumberDialog"));
        InputNumberDialog->resize(400, 264);
        buttonBox = new QDialogButtonBox(InputNumberDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(InputNumberDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 100, 201, 20));
        label = new QLabel(InputNumberDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 49, 89, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(InputNumberDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InputNumberDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InputNumberDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InputNumberDialog);
    } // setupUi

    void retranslateUi(QDialog *InputNumberDialog)
    {
        InputNumberDialog->setWindowTitle(QApplication::translate("InputNumberDialog", "Input the number", 0));
        label->setText(QApplication::translate("InputNumberDialog", "Number: ", 0));
    } // retranslateUi

};

namespace Ui {
    class InputNumberDialog: public Ui_InputNumberDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTNUMBER_H
