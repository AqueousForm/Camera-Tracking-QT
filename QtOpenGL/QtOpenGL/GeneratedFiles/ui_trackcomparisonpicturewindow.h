/********************************************************************************
** Form generated from reading UI file 'trackcomparisonpicturewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKCOMPARISONPICTUREWINDOW_H
#define UI_TRACKCOMPARISONPICTUREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trackcomparisonpicturewindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trackcomparisonpicturewindow)
    {
        if (trackcomparisonpicturewindow->objectName().isEmpty())
            trackcomparisonpicturewindow->setObjectName(QStringLiteral("trackcomparisonpicturewindow"));
        trackcomparisonpicturewindow->resize(873, 725);
        centralwidget = new QWidget(trackcomparisonpicturewindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);


        gridLayout->addLayout(verticalLayout_4, 1, 1, 1, 1);

        trackcomparisonpicturewindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(trackcomparisonpicturewindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 873, 21));
        trackcomparisonpicturewindow->setMenuBar(menubar);
        statusbar = new QStatusBar(trackcomparisonpicturewindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        trackcomparisonpicturewindow->setStatusBar(statusbar);

        retranslateUi(trackcomparisonpicturewindow);

        QMetaObject::connectSlotsByName(trackcomparisonpicturewindow);
    } // setupUi

    void retranslateUi(QMainWindow *trackcomparisonpicturewindow)
    {
        trackcomparisonpicturewindow->setWindowTitle(QApplication::translate("trackcomparisonpicturewindow", "Track Comparison Picture Window", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class trackcomparisonpicturewindow: public Ui_trackcomparisonpicturewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKCOMPARISONPICTUREWINDOW_H
