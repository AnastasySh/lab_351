#ifndef NEW_USER_H
#define NEW_USER_H

#include <QDialog>

namespace Ui {
class new_user;
}

class new_user : public QDialog
{
    Q_OBJECT

public:
    explicit new_user(QWidget *parent = nullptr, QByteArray name = nullptr);
    ~new_user();
signals:
    void createDyn ();

public slots:
    void create_dyn();    // СЛОТ-обработчик нажатия кнопки добавления


private:
    Ui::new_user *ui;
};

#endif // NEW_USER_H
