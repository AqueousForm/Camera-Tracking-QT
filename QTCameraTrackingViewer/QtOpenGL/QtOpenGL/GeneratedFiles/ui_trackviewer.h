/********************************************************************************
** Form generated from reading UI file 'trackviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKVIEWER_H
#define UI_TRACKVIEWER_H

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

class Ui_trackviewer
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

    void setupUi(QMainWindow *trackviewer)
    {
        if (trackviewer->objectName().isEmpty())
            trackviewer->setObjectName(QStringLiteral("trackviewer"));
        trackviewer->resize(800, 692);
        actionOpen_file = new QAction(trackviewer);
        actionOpen_file->setObjectName(QStringLiteral("actionOpen_file"));
        actionOpen_3D_points = new QAction(trackviewer);
        actionOpen_3D_points->setObjectName(QStringLiteral("actionOpen_3D_points"));
        centralwidget = new QWidget(trackviewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 781, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        trackviewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(trackviewer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView_Mode = new QMenu(menubar);
        menuView_Mode->setObjectName(QStringLiteral("menuView_Mode"));
        trackviewer->setMenuBar(menubar);
        statusbar = new QStatusBar(trackviewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        trackviewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView_Mode->menuAction());
        menuFile->addAction(actionOpen_file);
        menuFile->addAction(actionOpen_3D_points);

        retranslateUi(trackviewer);

        QMetaObject::connectSlotsByName(trackviewer);
    } // setupUi

    void retranslateUi(QMainWindow *trackviewer)
    {
        trackviewer->setWindowTitle(QApplication::translate("trackviewer", "Track Viewer", 0));
        actionOpen_file->setText(QApplication::translate("trackviewer", "Open file", 0));
        actionOpen_3D_points->setText(QApplication::translate("trackviewer", "Open 3D points", 0));
        menuFile->setTitle(QApplication::translate("trackviewer", "File", 0));
        menuView_Mode->setTitle(QApplication::translate("trackviewer", "View Mode", 0));
    } // retranslateUi

};

namespace Ui {
    class trackviewer: public Ui_trackviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKVIEWER_H
