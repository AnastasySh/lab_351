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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_user
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;

    void setupUi(QDialog *new_user)
    {
        if (new_user->objectName().isEmpty())
            new_user->setObjectName(QString::fromUtf8("new_user"));
        new_user->resize(449, 341);
        buttonBox = new QDialogButtonBox(new_user);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 280, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(new_user);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 20, 371, 241));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(new_user);
        QObject::connect(buttonBox, SIGNAL(accepted()), new_user, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), new_user, SLOT(reject()));

        QMetaObject::connectSlotsByName(new_user);
    } // setupUi

    void retranslateUi(QDialog *new_user)
    {
        new_user->setWindowTitle(QApplication::translate("new_user", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_user: public Ui_new_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_USER_H
