/********************************************************************************
** Form generated from reading UI file 'moder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODER_H
#define UI_MODER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_moder
{
public:
    QTableView *tableDB;
    QPushButton *new_button;
    QPushButton *delete_button;
    QPushButton *edit_button;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *moder)
    {
        if (moder->objectName().isEmpty())
            moder->setObjectName(QString::fromUtf8("moder"));
        moder->resize(902, 523);
        tableDB = new QTableView(moder);
        tableDB->setObjectName(QString::fromUtf8("tableDB"));
        tableDB->setGeometry(QRect(40, 40, 811, 361));
        new_button = new QPushButton(moder);
        new_button->setObjectName(QString::fromUtf8("new_button"));
        new_button->setGeometry(QRect(40, 410, 201, 21));
        delete_button = new QPushButton(moder);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        delete_button->setGeometry(QRect(660, 410, 191, 21));
        edit_button = new QPushButton(moder);
        edit_button->setObjectName(QString::fromUtf8("edit_button"));
        edit_button->setGeometry(QRect(310, 410, 271, 21));
        lineEdit = new QLineEdit(moder);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 460, 691, 21));
        label = new QLabel(moder);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 460, 47, 13));

        retranslateUi(moder);

        QMetaObject::connectSlotsByName(moder);
    } // setupUi

    void retranslateUi(QWidget *moder)
    {
        moder->setWindowTitle(QApplication::translate("moder", "Form", nullptr));
        new_button->setText(QApplication::translate("moder", "new user", nullptr));
        delete_button->setText(QApplication::translate("moder", "delete user", nullptr));
        edit_button->setText(QApplication::translate("moder", "edit user", nullptr));
        label->setText(QApplication::translate("moder", "search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class moder: public Ui_moder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODER_H
