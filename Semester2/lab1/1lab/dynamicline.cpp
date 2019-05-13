#include "dynamicline.h"

dynamicLine::dynamicLine(QWidget *parent) :
    QLabel(parent)
{
    LineID++;            // Увеличение счетчика на единицу
    LineID = ResLineID;   /* Присвоение кнопке номера, по которому будет производиться
                         * дальнейшая работа с кнопок
                         * */

}

dynamicLine::~dynamicLine()
{

}

/* Метод для возврата значения номера кнопки
 * */
int dynamicLine::getLineID()
{
    return LineID;
}

/* Инициализация статической переменной класса.
 * Статическая переменная класса должна инициализироваться в обязательном порядке
 * */
int dynamicLine::ResLineID = 0;

