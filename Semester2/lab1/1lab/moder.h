#ifndef MODER_H
#define MODER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTcpServer>
#include <QTcpSocket>
#include <QStandardItemModel>

namespace Ui {
class moder;
}

class moder : public QWidget
{
    Q_OBJECT

public:
    explicit moder(QWidget *parent = nullptr, QTcpSocket *ClientSock = nullptr);
    ~moder();
    QSqlTableModel  *model;
    QStandardItemModel* tableDB;
    void selectAllAnswer(QList <QByteArray> all);

private slots:
    void on_new_button_clicked(QByteArray name);

    void on_edit_button_clicked();

    void on_delete_button_clicked();

    void slot_read1(QByteArray arr);




private:
    Ui::moder *ui;
      QTcpSocket* ClientSocket;

    void setupModel(const QString &tableName, const QStringList &headers);
      void drawTable();
      void send_to_server(QString message);
       void createUI();


};

#endif // MODER_H
