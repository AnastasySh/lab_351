/********************************************************************************
** Form generated from reading UI file 'party_work.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTY_WORK_H
#define UI_PARTY_WORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Party_work
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Party_work)
    {
        if (Party_work->objectName().isEmpty())
            Party_work->setObjectName(QString::fromUtf8("Party_work"));
        Party_work->resize(400, 300);
        menuBar = new QMenuBar(Party_work);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Party_work->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Party_work);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Party_work->addToolBar(mainToolBar);
        centralWidget = new QWidget(Party_work);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Party_work->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Party_work);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Party_work->setStatusBar(statusBar);

        retranslateUi(Party_work);

        QMetaObject::connectSlotsByName(Party_work);
    } // setupUi

    void retranslateUi(QMainWindow *Party_work)
    {
        Party_work->setWindowTitle(QApplication::translate("Party_work", "Party_work", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Party_work: public Ui_Party_work {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTY_WORK_H
