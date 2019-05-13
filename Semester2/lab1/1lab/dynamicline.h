#ifndef DYNAMICLINE_H
#define DYNAMICLINE_H
#include <QLabel>

class dynamicLine : public QLabel
{
public:
    dynamicLine();// Q_OBJECT
public:
    explicit dynamicLine (QWidget *parent = nullptr);
    ~dynamicLine();
    static int ResLineID;  // Статическая переменная, счетчик номеров edit ов
    int getLineID();        // Функция для возврата локального номера edit а


public slots:

private:
    int LineID = 0;   // Локальная переменная, номер

};

#endif // DYNAMICEDIT_H
