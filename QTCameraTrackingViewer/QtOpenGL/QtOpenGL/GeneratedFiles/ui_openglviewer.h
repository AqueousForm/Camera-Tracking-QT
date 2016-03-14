/********************************************************************************
** Form generated from reading UI file 'openglviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLVIEWER_H
#define UI_OPENGLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openglviewer
{
public:
    QAction *actionOpen_file;
    QAction *actionOpen_3D_points;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView_Mode;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *openglviewer)
    {
        if (openglviewer->objectName().isEmpty())
            openglviewer->setObjectName(QStringLiteral("openglviewer"));
        openglviewer->resize(800, 692);
        actionOpen_file = new QAction(openglviewer);
        actionOpen_file->setObjectName(QStringLiteral("actionOpen_file"));
        actionOpen_3D_points = new QAction(openglviewer);
        actionOpen_3D_points->setObjectName(QStringLiteral("actionOpen_3D_points"));
        centralwidget = new QWidget(openglviewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 781, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        openglviewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(openglviewer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView_Mode = new QMenu(menubar);
        menuView_Mode->setObjectName(QStringLiteral("menuView_Mode"));
        openglviewer->setMenuBar(menubar);
        statusbar = new QStatusBar(openglviewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        openglviewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView_Mode->menuAction());
        menuFile->addAction(actionOpen_file);
        menuFile->addAction(actionOpen_3D_points);

        retranslateUi(openglviewer);

        QMetaObject::connectSlotsByName(openglviewer);
    } // setupUi

    void retranslateUi(QMainWindow *openglviewer)
    {
        openglviewer->setWindowTitle(QApplication::translate("openglviewer", "MainWindow", 0));
        actionOpen_file->setText(QApplication::translate("openglviewer", "Open file", 0));
        actionOpen_3D_points->setText(QApplication::translate("openglviewer", "Open 3D points", 0));
        menuFile->setTitle(QApplication::translate("openglviewer", "File", 0));
        menuView_Mode->setTitle(QApplication::translate("openglviewer", "View Mode", 0));
    } // retranslateUi

};

namespace Ui {
    class openglviewer: public Ui_openglviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLVIEWER_H
