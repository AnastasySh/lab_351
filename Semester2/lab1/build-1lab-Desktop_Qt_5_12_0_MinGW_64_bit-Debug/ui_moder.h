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
#include <QtWidgets/QFrame>
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
    QLineEdit *edit_search;
    QLabel *label;
    QPushButton *refrash;
    QPushButton *new_rec;
    QPushButton *edit_rec;
    QPushButton *delete_rec;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *log_edit;
    QLineEdit *pass_edit;
    QLineEdit *status_edit;
    QPushButton *ok_edit;
    QFrame *frame_del;
    QLabel *label_5;
    QPushButton *del_no;
    QPushButton *del_ok;

    void setupUi(QWidget *moder)
    {
        if (moder->objectName().isEmpty())
            moder->setObjectName(QString::fromUtf8("moder"));
        moder->resize(872, 508);
        tableDB = new QTableView(moder);
        tableDB->setObjectName(QString::fromUtf8("tableDB"));
        tableDB->setGeometry(QRect(10, 10, 551, 381));
        new_button = new QPushButton(moder);
        new_button->setObjectName(QString::fromUtf8("new_button"));
        new_button->setGeometry(QRect(30, 450, 191, 21));
        delete_button = new QPushButton(moder);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        delete_button->setGeometry(QRect(660, 450, 191, 21));
        edit_button = new QPushButton(moder);
        edit_button->setObjectName(QString::fromUtf8("edit_button"));
        edit_button->setGeometry(QRect(350, 450, 191, 21));
        edit_search = new QLineEdit(moder);
        edit_search->setObjectName(QString::fromUtf8("edit_search"));
        edit_search->setGeometry(QRect(160, 480, 691, 21));
        label = new QLabel(moder);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 480, 47, 13));
        refrash = new QPushButton(moder);
        refrash->setObjectName(QString::fromUtf8("refrash"));
        refrash->setGeometry(QRect(30, 410, 191, 21));
        new_rec = new QPushButton(moder);
        new_rec->setObjectName(QString::fromUtf8("new_rec"));
        new_rec->setGeometry(QRect(450, 410, 191, 21));
        edit_rec = new QPushButton(moder);
        edit_rec->setObjectName(QString::fromUtf8("edit_rec"));
        edit_rec->setGeometry(QRect(660, 410, 191, 21));
        delete_rec = new QPushButton(moder);
        delete_rec->setObjectName(QString::fromUtf8("delete_rec"));
        delete_rec->setGeometry(QRect(240, 410, 191, 21));
        frame = new QFrame(moder);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(580, 10, 261, 181));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 47, 13));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 47, 13));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 100, 47, 13));
        log_edit = new QLineEdit(frame);
        log_edit->setObjectName(QString::fromUtf8("log_edit"));
        log_edit->setGeometry(QRect(130, 20, 113, 21));
        pass_edit = new QLineEdit(frame);
        pass_edit->setObjectName(QString::fromUtf8("pass_edit"));
        pass_edit->setGeometry(QRect(130, 60, 113, 21));
        status_edit = new QLineEdit(frame);
        status_edit->setObjectName(QString::fromUtf8("status_edit"));
        status_edit->setGeometry(QRect(130, 100, 113, 21));
        ok_edit = new QPushButton(frame);
        ok_edit->setObjectName(QString::fromUtf8("ok_edit"));
        ok_edit->setGeometry(QRect(150, 150, 80, 21));
        frame_del = new QFrame(moder);
        frame_del->setObjectName(QString::fromUtf8("frame_del"));
        frame_del->setGeometry(QRect(570, 300, 281, 80));
        frame_del->setFrameShape(QFrame::StyledPanel);
        frame_del->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_del);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 251, 16));
        del_no = new QPushButton(frame_del);
        del_no->setObjectName(QString::fromUtf8("del_no"));
        del_no->setGeometry(QRect(179, 50, 91, 21));
        del_ok = new QPushButton(frame_del);
        del_ok->setObjectName(QString::fromUtf8("del_ok"));
        del_ok->setGeometry(QRect(90, 50, 80, 21));
        tableDB->raise();
        frame->raise();
        new_button->raise();
        delete_button->raise();
        edit_button->raise();
        edit_search->raise();
        label->raise();
        refrash->raise();
        new_rec->raise();
        edit_rec->raise();
        delete_rec->raise();
        frame_del->raise();

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
        refrash->setText(QApplication::translate("moder", "refrash", nullptr));
        new_rec->setText(QApplication::translate("moder", "new record", nullptr));
        edit_rec->setText(QApplication::translate("moder", "edit record", nullptr));
        delete_rec->setText(QApplication::translate("moder", "delete record", nullptr));
        label_2->setText(QApplication::translate("moder", "login", nullptr));
        label_3->setText(QApplication::translate("moder", "password", nullptr));
        label_4->setText(QApplication::translate("moder", "status", nullptr));
        ok_edit->setText(QApplication::translate("moder", "edit", nullptr));
        label_5->setText(QApplication::translate("moder", "Do you want to delete this record?", nullptr));
        del_no->setText(QApplication::translate("moder", "NONONONONO", nullptr));
        del_ok->setText(QApplication::translate("moder", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class moder: public Ui_moder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODER_H
