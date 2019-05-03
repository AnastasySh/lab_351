#include "new_user.h"
#include "ui_new_user.h"

new_user::new_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_user)
{
    ui->setupUi(this);
}

new_user::~new_user()
{
    delete ui;
}
