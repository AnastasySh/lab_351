/********************************************************************************
** Form generated from reading UI file 'delete_rec.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_REC_H
#define UI_DELETE_REC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_delete_rec
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *delete_rec)
    {
        if (delete_rec->objectName().isEmpty())
            delete_rec->setObjectName(QString::fromUtf8("delete_rec"));
        delete_rec->resize(400, 153);
        buttonBox = new QDialogButtonBox(delete_rec);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(delete_rec);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 321, 16));

        retranslateUi(delete_rec);
        QObject::connect(buttonBox, SIGNAL(accepted()), delete_rec, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), delete_rec, SLOT(reject()));

        QMetaObject::connectSlotsByName(delete_rec);
    } // setupUi

    void retranslateUi(QDialog *delete_rec)
    {
        delete_rec->setWindowTitle(QApplication::translate("delete_rec", "Dialog", nullptr));
        label->setText(QApplication::translate("delete_rec", "are you sure you want to delete this record?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_rec: public Ui_delete_rec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_REC_H
