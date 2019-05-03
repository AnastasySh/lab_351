#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <QWidget>

namespace Ui {
class user_manager;
}

class user_manager : public QWidget
{
    Q_OBJECT

public:
    explicit user_manager(QWidget *parent = nullptr);
    ~user_manager();

private:
    Ui::user_manager *ui;
};

#endif // USER_MANAGER_H
