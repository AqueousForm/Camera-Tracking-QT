/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QAction *actionAuthor;
    QAction *actionSettings;
    QAction *actionFrame;
    QAction *actionOpen;
    QAction *actionKeyFrame;
    QAction *actionGradually;
    QAction *actionOpen_1;
    QAction *actionOpen_2;
    QAction *actionView_pictures;
    QAction *actionStart;
    QAction *actionStart_2;
    QAction *actionStart_3;
    QAction *actionStart_4;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayoutMain;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuView_Track_Window;
    QMenu *menuView_Pictures_Window;
    QMenu *menuView_Track_Comparison_Window;
    QMenu *menuView_Picture_and_Track_Window;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 717);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QStringLiteral("actionAuthor"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionFrame = new QAction(MainWindow);
        actionFrame->setObjectName(QStringLiteral("actionFrame"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionKeyFrame = new QAction(MainWindow);
        actionKeyFrame->setObjectName(QStringLiteral("actionKeyFrame"));
        actionGradually = new QAction(MainWindow);
        actionGradually->setObjectName(QStringLiteral("actionGradually"));
        actionOpen_1 = new QAction(MainWindow);
        actionOpen_1->setObjectName(QStringLiteral("actionOpen_1"));
        actionOpen_2 = new QAction(MainWindow);
        actionOpen_2->setObjectName(QStringLiteral("actionOpen_2"));
        actionView_pictures = new QAction(MainWindow);
        actionView_pictures->setObjectName(QStringLiteral("actionView_pictures"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStart_2 = new QAction(MainWindow);
        actionStart_2->setObjectName(QStringLiteral("actionStart_2"));
        actionStart_3 = new QAction(MainWindow);
        actionStart_3->setObjectName(QStringLiteral("actionStart_3"));
        actionStart_4 = new QAction(MainWindow);
        actionStart_4->setObjectName(QStringLiteral("actionStart_4"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayoutMain = new QVBoxLayout();
        verticalLayoutMain->setSpacing(6);
        verticalLayoutMain->setObjectName(QStringLiteral("verticalLayoutMain"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayoutMain->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayoutMain->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayoutMain);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuView_Track_Window = new QMenu(menuBar);
        menuView_Track_Window->setObjectName(QStringLiteral("menuView_Track_Window"));
        menuView_Pictures_Window = new QMenu(menuBar);
        menuView_Pictures_Window->setObjectName(QStringLiteral("menuView_Pictures_Window"));
        menuView_Track_Comparison_Window = new QMenu(menuBar);
        menuView_Track_Comparison_Window->setObjectName(QStringLiteral("menuView_Track_Comparison_Window"));
        menuView_Picture_and_Track_Window = new QMenu(menuBar);
        menuView_Picture_and_Track_Window->setObjectName(QStringLiteral("menuView_Picture_and_Track_Window"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView_Track_Window->menuAction());
        menuBar->addAction(menuView_Pictures_Window->menuAction());
        menuBar->addAction(menuView_Track_Comparison_Window->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuView_Picture_and_Track_Window->menuAction());
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAuthor);
        menuView_Track_Window->addAction(actionStart);
        menuView_Pictures_Window->addAction(actionStart_2);
        menuView_Track_Comparison_Window->addAction(actionStart_3);
        menuView_Picture_and_Track_Window->addAction(actionStart_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Camera Tracking", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        actionAuthor->setText(QApplication::translate("MainWindow", "Author", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionFrame->setText(QApplication::translate("MainWindow", "Continuous Frames", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionKeyFrame->setText(QApplication::translate("MainWindow", "Key Frames", 0));
        actionGradually->setText(QApplication::translate("MainWindow", "Gradually", 0));
        actionOpen_1->setText(QApplication::translate("MainWindow", "Open_2", 0));
        actionOpen_2->setText(QApplication::translate("MainWindow", "Open_3", 0));
        actionView_pictures->setText(QApplication::translate("MainWindow", "view pictures", 0));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0));
        actionStart_2->setText(QApplication::translate("MainWindow", "Start", 0));
        actionStart_3->setText(QApplication::translate("MainWindow", "Start", 0));
        actionStart_4->setText(QApplication::translate("MainWindow", "Start", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuView_Track_Window->setTitle(QApplication::translate("MainWindow", "View Track Window", 0));
        menuView_Pictures_Window->setTitle(QApplication::translate("MainWindow", "View Pictures Window", 0));
        menuView_Track_Comparison_Window->setTitle(QApplication::translate("MainWindow", "View Track Comparison Window", 0));
        menuView_Picture_and_Track_Window->setTitle(QApplication::translate("MainWindow", "View Picture and Track Window", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
