#include "delete_rec.h"
#include "ui_delete_rec.h"
#include <QMessageBox>

delete_rec::delete_rec(QWidget *parent, QTcpSocket *ClientSock) :
    QDialog(parent),
    ui(new Ui::delete_rec)

{
    ui->setupUi(this);
    ClientSocket = ClientSock;
    connect(parent,SIGNAL(get_index), this, SLOT(put_index));
    //model->itemData();
    int row = 1;
    if(row == -1){
     QMessageBox M;
     M.setText("record not found. try again");
     M.show();
       /* В противном случае диалог настраивается на заданную запись
        * */
       } 
    else {
           mapper->setCurrentModelIndex(model->index(row,0));
       }

}

delete_rec::~delete_rec()
{
    delete ui;
}

void delete_rec::on_buttonBox_accepted()
{
    QString message = "yeeeees";
    QByteArray array;
    array.append(message);
    ClientSocket->write(array);
}
void delete_rec::put_index(QModelIndex index)
{
    QString message = "yeeeees";
    QByteArray array;
    array.append(message);
    ClientSocket->write(array);
}

