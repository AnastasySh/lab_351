#ifndef NEW_USER_H
#define NEW_USER_H

#include <QDialog>
#include <QAbstractButton>
#include <QTcpSocket>

namespace Ui {
class new_user;
}

class new_user : public QDialog
{
    Q_OBJECT

public:
    explicit new_user(QWidget *parent = nullptr, QTcpSocket *ClientSock = nullptr, QString name = nullptr);
    ~new_user();
signals:
    //void createDyn ();

public slots:
   // void create_dyn();    // СЛОТ-обработчик нажатия кнопки добавления


private slots:

    void on_buttonBox_accepted();

private:
    Ui::new_user *ui;
    QTcpSocket *ClientSocket;
};

#endif // NEW_USER_H
