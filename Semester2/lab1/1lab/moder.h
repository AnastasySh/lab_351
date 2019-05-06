#ifndef MODER_H
#define MODER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class moder;
}

class moder : public QWidget
{
    Q_OBJECT

public:
    explicit moder(QWidget *parent = nullptr, QTcpSocket *ClientSocket = nullptr);
    ~moder();
    QSqlTableModel  *model;

private slots:
    void on_new_button_clicked();

    void on_edit_button_clicked();

    void on_delete_button_clicked();

    void send_to_server(QString message);

private:
    Ui::moder *ui;
      void setupModel(const QString &tableName, const QStringList &headers);
       void createUI();
       QTcpSocket* ClientSocket;
};

#endif // MODER_H