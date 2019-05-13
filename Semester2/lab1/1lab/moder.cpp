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

moder::moder(QWidget *parent, QTcpSocket *ClientSock) :
    QWidget(parent),
    ui(new Ui::moder)
{
    ui->setupUi(this);
    ClientSocket = ClientSock;
    connect(parent,SIGNAL(readyReadfromMainWindow(QByteArray)),this,SLOT(slot_read1(QByteArray)));
    send_to_server("selectAll&*&user");
}

moder::~moder()
{
    delete ui;
}
void moder::drawTable(){
tableDB = new QStandardItemModel(1, 6, this);
QStandardItem *item;
ui->tableDB->setModel(tableDB);
tableDB->setHeaderData(0, Qt::Horizontal, "login");
tableDB->setHeaderData(1, Qt::Horizontal, "password");
tableDB->setHeaderData(2, Qt::Horizontal, "status");

/*
query.exec("SELECT * FROM database");
QSqlRecord rec = query.record();
const int idIndex = rec.indexOf( "id");
const int fioIndex = rec.indexOf( "fio");
const int typeIndex = rec.indexOf( "type");
const int priceIndex = rec.indexOf("price");
const int countIndex = rec.indexOf("count");
const int dateIndex = rec.indexOf( "date");

while(query.next()){
item = new QStandardItem(query.value(idIndex).toString());
tableDB->setItem(i, 0, item);
item = new QStandardItem(query.value(fioIndex).toString());
tableDB->setItem(i, 1, item);
item = new QStandardItem(query.value(typeIndex).toString());
tableDB->setItem(i, 2, item);
item = new QStandardItem(query.value(priceIndex).toString());
tableDB->setItem(i, 3, item);
item = new QStandardItem(query.value(countIndex).toString());
tableDB->setItem(i, 4, item);
item = new QStandardItem(query.value(dateIndex).toString());
tableDB->setItem(i, 5, item);
i++;

}*/
}

void moder::on_new_button_clicked( QByteArray name)
{
    new_user *N = new new_user (nullptr, name);
    N ->show();
}

void moder::on_edit_button_clicked()
{
    new_user *N = new new_user;
    N ->show();
}

void moder::selectAllAnswer(QList <QByteArray> all){
    int n = all[1].toInt();
    tableDB = new QStandardItemModel(1, n, this);
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
    delete_rec *D = new delete_rec;
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
void moder::send_to_server(QString message)
{
QByteArray array;
array.append(message);
ClientSocket -> write(array); // то что мы отправляем. в виде Qstring
}
