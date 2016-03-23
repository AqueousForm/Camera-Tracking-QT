/********************************************************************************
** Form generated from reading UI file 'trackcomparisonviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKCOMPARISONVIEWER_H
#define UI_TRACKCOMPARISONVIEWER_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trackcomparisonviewer
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trackcomparisonviewer)
    {
        if (trackcomparisonviewer->objectName().isEmpty())
            trackcomparisonviewer->setObjectName(QStringLiteral("trackcomparisonviewer"));
        trackcomparisonviewer->resize(851, 677);
        actionOpen = new QAction(trackcomparisonviewer);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralwidget = new QWidget(trackcomparisonviewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);

        trackcomparisonviewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(trackcomparisonviewer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 851, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        trackcomparisonviewer->setMenuBar(menubar);
        statusbar = new QStatusBar(trackcomparisonviewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        trackcomparisonviewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(trackcomparisonviewer);

        QMetaObject::connectSlotsByName(trackcomparisonviewer);
    } // setupUi

    void retranslateUi(QMainWindow *trackcomparisonviewer)
    {
        trackcomparisonviewer->setWindowTitle(QApplication::translate("trackcomparisonviewer", "Track Comparison Viewer", 0));
        actionOpen->setText(QApplication::translate("trackcomparisonviewer", "Open", 0));
        menuFile->setTitle(QApplication::translate("trackcomparisonviewer", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class trackcomparisonviewer: public Ui_trackcomparisonviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKCOMPARISONVIEWER_H
