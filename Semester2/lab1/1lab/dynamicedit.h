#ifndef DYNAMICEDIT_H
#define DYNAMICEDIT_H
#include <QLineEdit>

class dynamicEdit : public QLineEdit
{
public:
    dynamicEdit();// Q_OBJECT
public:
    explicit dynamicEdit (QWidget *parent = nullptr);
    ~dynamicEdit();
    static int ResEditID;  // Статическая переменная, счетчик номеров edit ов
    int getEditID();        // Функция для возврата локального номера edit а


public slots:

private:
    int EditID = 0;   // Локальная переменная, номер

};

#endif // DYNAMICEDIT_H
