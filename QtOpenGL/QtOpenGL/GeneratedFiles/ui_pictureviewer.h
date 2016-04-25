/********************************************************************************
** Form generated from reading UI file 'pictureviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREVIEWER_H
#define UI_PICTUREVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictureViewer
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QLabel *label;
    QScrollBar *horizontalScrollBar;
    QTextEdit *textEdit;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PictureViewer)
    {
        if (PictureViewer->objectName().isEmpty())
            PictureViewer->setObjectName(QStringLiteral("PictureViewer"));
        PictureViewer->resize(1074, 704);
        actionOpen = new QAction(PictureViewer);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralwidget = new QWidget(PictureViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 40, 831, 461));
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(10, 560, 771, 20));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 120, 104, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 61, 21));
        PictureViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PictureViewer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1074, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        PictureViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(PictureViewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PictureViewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(PictureViewer);

        QMetaObject::connectSlotsByName(PictureViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PictureViewer)
    {
        PictureViewer->setWindowTitle(QApplication::translate("PictureViewer", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("PictureViewer", "Open", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("PictureViewer", "number", 0));
        menuFile->setTitle(QApplication::translate("PictureViewer", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class PictureViewer: public Ui_PictureViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREVIEWER_H
