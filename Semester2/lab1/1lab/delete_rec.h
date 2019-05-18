#ifndef DELETE_REC_H
#define DELETE_REC_H

#include <QDialog>
#include <QTcpSocket>
#include <QSqlTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class delete_rec;
}

class delete_rec : public QDialog
{
    Q_OBJECT

public:
    explicit delete_rec(QWidget *parent = nullptr, QTcpSocket *ClientSock = nullptr);
    ~delete_rec();

private slots:
    void on_buttonBox_accepted();
    void put_index(QModelIndex index);

private:
    Ui::delete_rec *ui;
    QTcpSocket *ClientSocket;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
    void setupModel();
    void createUI();

};

#endif // DELETE_REC_H

