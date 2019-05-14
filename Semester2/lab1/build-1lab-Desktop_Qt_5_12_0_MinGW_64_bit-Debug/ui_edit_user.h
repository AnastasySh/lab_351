/********************************************************************************
** Form generated from reading UI file 'edit_user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_USER_H
#define UI_EDIT_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_edit_user
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *loginEdit;
    QLineEdit *statusEdit;
    QLineEdit *passwordEdit;
    QLabel *passwordlabel;
    QLabel *loginlabel;
    QLabel *statusLabel;

    void setupUi(QDialog *edit_user)
    {
        if (edit_user->objectName().isEmpty())
            edit_user->setObjectName(QString::fromUtf8("edit_user"));
        edit_user->resize(480, 300);
        buttonBox = new QDialogButtonBox(edit_user);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        loginEdit = new QLineEdit(edit_user);
        loginEdit->setObjectName(QString::fromUtf8("loginEdit"));
        loginEdit->setGeometry(QRect(120, 60, 311, 21));
        statusEdit = new QLineEdit(edit_user);
        statusEdit->setObjectName(QString::fromUtf8("statusEdit"));
        statusEdit->setGeometry(QRect(120, 160, 311, 21));
        passwordEdit = new QLineEdit(edit_user);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(120, 110, 311, 21));
        passwordlabel = new QLabel(edit_user);
        passwordlabel->setObjectName(QString::fromUtf8("passwordlabel"));
        passwordlabel->setGeometry(QRect(50, 110, 47, 13));
        loginlabel = new QLabel(edit_user);
        loginlabel->setObjectName(QString::fromUtf8("loginlabel"));
        loginlabel->setGeometry(QRect(50, 60, 47, 13));
        statusLabel = new QLabel(edit_user);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(50, 170, 47, 13));

        retranslateUi(edit_user);
        QObject::connect(buttonBox, SIGNAL(rejected()), edit_user, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), edit_user, SLOT(accept()));

        QMetaObject::connectSlotsByName(edit_user);
    } // setupUi

    void retranslateUi(QDialog *edit_user)
    {
        edit_user->setWindowTitle(QApplication::translate("edit_user", "Dialog", nullptr));
        passwordlabel->setText(QApplication::translate("edit_user", "password", nullptr));
        loginlabel->setText(QApplication::translate("edit_user", "login", nullptr));
        statusLabel->setText(QApplication::translate("edit_user", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class edit_user: public Ui_edit_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_USER_H
