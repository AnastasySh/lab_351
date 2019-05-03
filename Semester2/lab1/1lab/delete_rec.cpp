#include "delete_rec.h"
#include "ui_delete_rec.h"

delete_rec::delete_rec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_rec)
{
    ui->setupUi(this);
}

delete_rec::~delete_rec()
{
    delete ui;
}
