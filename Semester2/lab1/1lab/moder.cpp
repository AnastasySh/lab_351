#include "moder.h"
#include "new_user.h"
#include "mainwindow.h"
#include "ui_moder.h"
#include "delete_rec.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include <QTcpServer>
#include <QTcpSocket>
#include <QStandardItemModel>
#include "edit_user.h"

moder::moder(QWidget *parent, QTcpSocket *ClientSock, QString stat) :
    QWidget(parent),
    ui(new Ui::moder) //сделано, открытие окон под разных пользователей
{
    ui->setupUi(this);
    if(stat == "moder")
    {
        status = stat;
        ui ->new_rec -> hide();
        ui ->delete_rec -> hide();
        ui ->edit_rec ->hide();


    }
    else if (stat == "manager") {
        status = stat;
        ui ->new_button -> hide();
        ui ->edit_button -> hide();
        ui ->delete_button -> hide();
    }
    else if (stat == "user") {
        status = stat;
        ui ->new_button -> hide();
        ui ->edit_button -> hide();
        ui ->delete_button -> hide();
        ui ->new_rec -> hide();
        ui ->delete_rec -> hide();
        ui ->edit_rec ->hide();
    }
     ClientSocket = ClientSock;
     connect(parent,SIGNAL(readyReadfromMainWindow(QByteArray)),this,SLOT(slot_read1(QByteArray)));
     if (status == "user" || status == "manager"){
        send_to_server("selectAll&*&party");
     }
     else {
        send_to_server("selectAll&*&user");
     }
}

moder::~moder()
{
    delete ui;
}


void moder::on_new_button_clicked()
{
    new_user *N = new new_user (nullptr,ClientSocket);
    N ->show();
}

void moder::on_edit_button_clicked()
{
    edit_user *N = new edit_user(nullptr, ClientSocket);
    N ->show();
}

void moder::selectAllAnswer(QList <QByteArray> all){ // сделано. построение таблицы
    int n = all[1].toInt();
    tableDB = new QStandardItemModel(0, n, this);
    // Разрешаем выделение строк
    ui->tableDB->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableDB->setSelectionMode(QAbstractItemView::SingleSelection);

    QStandardItem *item;
    ui->tableDB->setModel(tableDB);
    for (int i = 0; i < n; i++){
        tableDB->setHeaderData(i, Qt::Horizontal, all[i+2]);
    }
    int m =0;
    int k = 0;
    for (int i = 0; i < (all.size()-n-2); i++) {
        if (i>0){
            if (i%n==0){
                k+=1;
        }
        }
        item = new QStandardItem(QString::fromStdString(all[i+2+n].toStdString()));
        if (m == all[1].toInt()){
            m = 0;
        }
        tableDB->setItem(k, m, item);
        m++;
    }
 }

void moder::on_delete_button_clicked()
{
    QModelIndex index = ui->tableDB->selectionModel()->currentIndex();
    emit get_index(index);
    delete_rec *D = new delete_rec();
    D ->show();
}

void moder::slot_read1(QByteArray array){

        QList <QByteArray> all = array.split('&');
        if (all[0] == "selectAllAnswer" || all[0] == "selectAnswer"){
          selectAllAnswer(all);
        }
        else if (all[0] == "DeleteAnswer") {

        }
}
void moder::send_to_server(QString message) //сделано. отправка серверу
{
QByteArray array;
array.append(message);
ClientSocket -> write(array);
}

void moder::on_refrash_clicked() //сделано. обновление страницы
{
    if(status == "moder"){
        send_to_server("selectAll&*&user");
        qDebug() << "refresh moder";
    }
    else {
        send_to_server("selectAll&*&party");
        qDebug() << "refresh user";

    }

}
