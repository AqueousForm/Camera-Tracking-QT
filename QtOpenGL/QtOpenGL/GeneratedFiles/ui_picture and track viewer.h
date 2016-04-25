/********************************************************************************
** Form generated from reading UI file 'picture and track viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_20_AND_20_TRACK_20_VIEWER_H
#define UI_PICTURE_20_AND_20_TRACK_20_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_picturetrackwindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *picturetrackwindow)
    {
        if (picturetrackwindow->objectName().isEmpty())
            picturetrackwindow->setObjectName(QStringLiteral("picturetrackwindow"));
        picturetrackwindow->resize(798, 632);
        actionOpen = new QAction(picturetrackwindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralwidget = new QWidget(picturetrackwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMaximumSize(QSize(700, 700));

        horizontalLayout_2->addWidget(graphicsView);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        horizontalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(horizontalLayout);

        picturetrackwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(picturetrackwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 798, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        picturetrackwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(picturetrackwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        picturetrackwindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(picturetrackwindow);

        QMetaObject::connectSlotsByName(picturetrackwindow);
    } // setupUi

    void retranslateUi(QMainWindow *picturetrackwindow)
    {
        picturetrackwindow->setWindowTitle(QApplication::translate("picturetrackwindow", "Picture and Track Window", 0));
        actionOpen->setText(QApplication::translate("picturetrackwindow", "Open", 0));
        menuFile->setTitle(QApplication::translate("picturetrackwindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class picturetrackwindow: public Ui_picturetrackwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_20_AND_20_TRACK_20_VIEWER_H
