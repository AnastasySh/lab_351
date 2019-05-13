#include "new_user.h"
#include "ui_new_user.h"
#include "dynamicedit.h"
#include "dynamicline.h"

new_user::new_user(QWidget *parent, QByteArray name) :
    QDialog(parent),
    ui(new Ui::new_user)
{
    ui->setupUi(this);
    emit createDyn();
}

new_user::~new_user()
{
    delete ui;
}

void new_user::create_dyn()
{
    dynamicLine *line = new dynamicLine (this);
    dynamicEdit *edit = new dynamicEdit (this);
    ui->formLayout->addWidget(line);
    ui->formLayout->addWidget(edit);

   //connect(edit, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
};
