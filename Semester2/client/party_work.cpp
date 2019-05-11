#include "party_work.h"
#include "ui_party_work.h"
#include <qfile.h>
#include <qdebug.h>
#include<qstring.h>
#include <QCryptographicHash>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QCoreApplication>
#include <QTextStream>
#include <QBitArray>
#include <QMessageBox>

Party_work::Party_work(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Party_work)
{
    ui->setupUi(this);

}

Party_work::~Party_work()
{
    delete ui;
}

void Party_work::slot_connected()
{
    QMessageBox Msg;
    Msg.setText("Connected!");
    Msg.exec();

};
void Party_work::slot_read()
{
    while(ClientSocket -> bytesAvailable()>0){
        QByteArray array;
        array = ClientSocket -> readAll();
        QList <QByteArray> all = array.split('&');
        if (all[0] == "authAnswer"){
            if(all[1] == "moder"){
                moder *M = new moder(nullptr, ClientSocket);
                M ->show();
            }
            else if (all[1] == "manager") {
                moder *M = new moder(nullptr, ClientSocket);
                M ->show();
            }
            else {
                moder *M = new moder;
                M ->show();
            }
        }
        else if (all[0] == "selectAllAnswer") {

        }

  }

 //int idusersocs=ClientSocket->socketDescriptor();

};
void Party_work::send_to_server (QString message)
{
QByteArray array;
array.append(message);
ClientSocket->write(array);// то что мы отправляем. в виде Qstring
};
void Party_work::disconnected()
{

};
