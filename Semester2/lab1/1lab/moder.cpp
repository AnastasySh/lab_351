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
#include <QMessageBox>

moder::moder(QWidget *parent, QTcpSocket *ClientSock, QString stat) :
    QWidget(parent),
    ui(new Ui::moder) //сделано, открытие окон под разных пользователей
{
    ui->setupUi(this);
    if(stat == "moder")
    {
        status = stat;
        ui->frame ->hide();
        ui->frame_del ->hide();
        ui ->new_rec -> hide();
        ui ->delete_rec -> hide();
        ui ->edit_rec ->hide();


    }
    else if (stat == "manager") {
        status = stat;
        ui->frame ->hide();
        ui->frame_del ->hide();
        ui ->new_button -> hide();
        ui ->edit_button -> hide();
        ui ->delete_button -> hide();
    }
    else if (stat == "user") {
        status = stat;
        ui->frame ->hide();
        ui->frame_del ->hide();
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
    ui ->frame -> show();
    QModelIndex index = ui->tableDB->selectionModel()->currentIndex();
    int row = index.row();
    /*index = ui->tableDB->model() ->index(row, 0);
    QVariant query= ui->tableDB->model()->data(index);
    index = ui->tableDB->model() ->index(row, 1);
    query= ui->tableDB->model()->data(index);
    index = ui->tableDB->model() ->index(row, 2);
    query= ui->tableDB->model()->data(index);*/
    ui->log_edit->setText(ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 0)).toString());
    ui->pass_edit->setText(ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 1)).toString());
    ui->status_edit->setText(ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 2)).toString());

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
   ui->frame_del ->show();


}

void moder::slot_read1(QByteArray array){

        QList <QByteArray> all = array.split('&');
        if (all[0] == "selectAllAnswer"){
          selectAllAnswer(all);
        }
        else if (all[0] == "selectAnswer"){
           selectAllAnswer(all);
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

void moder::on_ok_edit_clicked()
{
    QString log = ui->log_edit->text();
    QString pass = ui->pass_edit->text();
    QString status = ui->status_edit->text();
    QModelIndex index = ui->tableDB->selectionModel()->currentIndex();
    int row = index.row();
    QString lastLog = ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 0)).toString();
    QString lastPass = ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 1)).toString();
    QString lastStatus = ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 2)).toString();
    send_to_server("update&user&"+lastLog+","+lastPass+","+lastStatus+","+log+","+pass+","+status);
    QMessageBox* pmbx =
                        new QMessageBox();
    pmbx->setText("ou");
    pmbx->exec();
    delete pmbx;
    ui->frame->hide();

}

void moder::on_del_ok_clicked()
{
    QModelIndex index = ui->tableDB->selectionModel()->currentIndex();
    int row = index.row();
    QString lastLog = ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 0)).toString();
    QString lastPass = ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 1)).toString();
    QString lastStatus = ui->tableDB->model()->data(ui->tableDB->model() ->index(row, 2)).toString();
    send_to_server("deleteRec&user&"+lastLog+","+lastPass+","+lastStatus);

    QMessageBox* pmbx =
                        new QMessageBox();
    pmbx->setText("AAAAAAAAAAAAA");
    pmbx->exec();
    delete pmbx;
    ui->frame_del->hide();

}

void moder::on_del_no_clicked()
{
    ui->frame_del->hide();
}



void moder::on_edit_search_editingFinished()
{


         QString condition = ui->edit_search->text();
         send_to_server("select&*&user&"+condition);

}
