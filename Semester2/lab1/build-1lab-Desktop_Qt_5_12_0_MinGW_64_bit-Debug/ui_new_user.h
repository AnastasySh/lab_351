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
    QLabel *loginlabel;
    QLabel *passwordlabel;
    QLabel *statusLabel;
    QLineEdit *statusEdit;
    QLineEdit *passwordEdit;
    QLineEdit *loginEdit;

    void setupUi(QDialog *new_user)
    {
        if (new_user->objectName().isEmpty())
            new_user->setObjectName(QString::fromUtf8("new_user"));
        new_user->resize(428, 276);
        buttonBox = new QDialogButtonBox(new_user);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        loginlabel = new QLabel(new_user);
        loginlabel->setObjectName(QString::fromUtf8("loginlabel"));
        loginlabel->setGeometry(QRect(20, 50, 47, 13));
        passwordlabel = new QLabel(new_user);
        passwordlabel->setObjectName(QString::fromUtf8("passwordlabel"));
        passwordlabel->setGeometry(QRect(20, 100, 47, 13));
        statusLabel = new QLabel(new_user);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(20, 160, 47, 13));
        statusEdit = new QLineEdit(new_user);
        statusEdit->setObjectName(QString::fromUtf8("statusEdit"));
        statusEdit->setGeometry(QRect(90, 150, 311, 21));
        passwordEdit = new QLineEdit(new_user);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(90, 100, 311, 21));
        loginEdit = new QLineEdit(new_user);
        loginEdit->setObjectName(QString::fromUtf8("loginEdit"));
        loginEdit->setGeometry(QRect(90, 50, 311, 21));

        retranslateUi(new_user);
        QObject::connect(buttonBox, SIGNAL(accepted()), new_user, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), new_user, SLOT(reject()));

        QMetaObject::connectSlotsByName(new_user);
    } // setupUi

    void retranslateUi(QDialog *new_user)
    {
        new_user->setWindowTitle(QApplication::translate("new_user", "Dialog", nullptr));
        loginlabel->setText(QApplication::translate("new_user", "login", nullptr));
        passwordlabel->setText(QApplication::translate("new_user", "password", nullptr));
        statusLabel->setText(QApplication::translate("new_user", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_user: public Ui_new_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_USER_H
