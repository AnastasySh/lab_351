#ifndef DELETE_REC_H
#define DELETE_REC_H

#include <QDialog>
#include <QTcpSocket>

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

private:
    Ui::delete_rec *ui;
    QTcpSocket *ClientSocket;
};

#endif // DELETE_REC_H

