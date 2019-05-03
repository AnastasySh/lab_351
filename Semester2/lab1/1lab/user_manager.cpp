#include "user_manager.h"
#include "ui_user_manager.h"

user_manager::user_manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_manager)
{
    ui->setupUi(this);
}

user_manager::~user_manager()
{
    delete ui;
}
