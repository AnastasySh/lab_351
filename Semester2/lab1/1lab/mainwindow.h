#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTcpSocket* get_socket();

private slots: // cлоты которые есть в окне
    void on_pushButton_clicked();
    void slot_connected();
    void slot_read();
    void send_to_server (QString message);
    void disconnected();


private:
    Ui::MainWindow *ui;
     QTcpSocket *ClientSocket; // создание сокета
};



#endif // MAINWINDOW_H
