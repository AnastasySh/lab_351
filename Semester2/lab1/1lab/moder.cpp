#include "moder.h"
#include "new_user.h"
#include "mainwindow.h"
#include "ui_moder.h"
#include "delete_rec.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include <QTcpServer>
#include <QTcpSocket>

moder::moder(QWidget *parent, QTcpSocket *ClientSock) :
    QWidget(parent),
    ui(new Ui::moder)
{

    ui->setupUi(this);

    ClientSocket = ClientSock;
    //connect(ClientSocket,SIGNAL( connected() ),this,SLOT( slot_connected() ) ); // что-то не так с этими двумя строками
    //connect(ClientSocket,SIGNAL(readyRead()),this,SLOT(slot_read()));

    this->setupModel("test",
                     QStringList() << trUtf8("login")
                                   << trUtf8("password")
                                   << trUtf8("data")
     );

    /* Инициализируем внешний вид таблицы с данными
     * */
    this->createUI();
    send_to_server("select&*&Test&");
}

moder::~moder()
{
    delete ui;


}
void moder::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    model = new QSqlTableModel(this);
    model->setTable(tableName);

    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    //model->setSort(0,Qt::AscendingOrder);
}

void moder::createUI()
{
    ui->tableView->setModel(model);     // Устанавливаем модель на TableView
    //ui->tableView->setColumnHidden(0, true);    // Скрываем колонку. эт не нужно но пусть будет
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select(); // Делаем выборку данных из таблицы
}



void moder::on_new_button_clicked()
{
    new_user *N = new new_user;
    N ->show();
}

void moder::on_edit_button_clicked()
{
    new_user *N = new new_user;
    N ->show();
}

void moder::on_delete_button_clicked()
{
    delete_rec *D = new delete_rec;
    D ->show();
}

void moder::send_to_server(QString message)
{
QByteArray array;
array.append(message);
ClientSocket -> write(array); // то что мы отправляем. в виде Qstring
};
