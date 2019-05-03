/********************************************************************************
** Form generated from reading UI file 'user_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MANAGER_H
#define UI_USER_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_manager
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *user_manager)
    {
        if (user_manager->objectName().isEmpty())
            user_manager->setObjectName(QString::fromUtf8("user_manager"));
        user_manager->resize(614, 361);
        tableView = new QTableView(user_manager);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 30, 391, 301));
        pushButton = new QPushButton(user_manager);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 70, 171, 21));
        label = new QLabel(user_manager);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 30, 47, 13));
        lineEdit = new QLineEdit(user_manager);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(470, 30, 131, 21));
        pushButton_2 = new QPushButton(user_manager);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 100, 171, 21));
        pushButton_3 = new QPushButton(user_manager);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(430, 130, 171, 21));

        retranslateUi(user_manager);

        QMetaObject::connectSlotsByName(user_manager);
    } // setupUi

    void retranslateUi(QWidget *user_manager)
    {
        user_manager->setWindowTitle(QApplication::translate("user_manager", "Form", nullptr));
        pushButton->setText(QApplication::translate("user_manager", "PushButton", nullptr));
        label->setText(QApplication::translate("user_manager", "search", nullptr));
        pushButton_2->setText(QApplication::translate("user_manager", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("user_manager", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_manager: public Ui_user_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MANAGER_H
