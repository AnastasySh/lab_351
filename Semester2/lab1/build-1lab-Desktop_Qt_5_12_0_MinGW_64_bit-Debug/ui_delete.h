/********************************************************************************
** Form generated from reading UI file 'delete.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_H
#define UI_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_delete
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *delete)
    {
        if (delete->objectName().isEmpty())
            delete->setObjectName(QString::fromUtf8("delete"));
        delete->resize(400, 141);
        buttonBox = new QDialogButtonBox(delete);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 100, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(delete);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 321, 16));

        retranslateUi(delete);
        QObject::connect(buttonBox, SIGNAL(accepted()), delete, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), delete, SLOT(reject()));

        QMetaObject::connectSlotsByName(delete);
    } // setupUi

    void retranslateUi(QDialog *delete)
    {
        delete->setWindowTitle(QApplication::translate("delete", "Dialog", nullptr));
        label->setText(QApplication::translate("delete", "are you sure you want to delete this record?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete: public Ui_delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_H
