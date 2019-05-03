/********************************************************************************
** Form generated from reading UI file 'new_user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_USER_H
#define UI_NEW_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_new_user
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *new_user)
    {
        if (new_user->objectName().isEmpty())
            new_user->setObjectName(QString::fromUtf8("new_user"));
        new_user->resize(400, 300);
        buttonBox = new QDialogButtonBox(new_user);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(new_user);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 90, 231, 21));
        lineEdit_2 = new QLineEdit(new_user);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 130, 231, 21));
        lineEdit_3 = new QLineEdit(new_user);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 170, 231, 21));
        label = new QLabel(new_user);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 90, 47, 13));
        label_2 = new QLabel(new_user);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 130, 61, 16));
        label_3 = new QLabel(new_user);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 170, 47, 13));

        retranslateUi(new_user);
        QObject::connect(buttonBox, SIGNAL(accepted()), new_user, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), new_user, SLOT(reject()));

        QMetaObject::connectSlotsByName(new_user);
    } // setupUi

    void retranslateUi(QDialog *new_user)
    {
        new_user->setWindowTitle(QApplication::translate("new_user", "Dialog", nullptr));
        label->setText(QApplication::translate("new_user", "login", nullptr));
        label_2->setText(QApplication::translate("new_user", "password", nullptr));
        label_3->setText(QApplication::translate("new_user", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_user: public Ui_new_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_USER_H
