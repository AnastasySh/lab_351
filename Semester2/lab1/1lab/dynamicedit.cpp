#include "dynamicedit.h"

dynamicEdit::dynamicEdit(QWidget *parent) :
    QLineEdit(parent)
{
    ResEditID++;            // Увеличение счетчика на единицу
    EditID = ResEditID;   /* Присвоение кнопке номера, по которому будет производиться
                         * дальнейшая работа с кнопок
                         * */

}

dynamicEdit::~dynamicEdit()
{

}

/* Метод для возврата значения номера кнопки
 * */
int dynamicEdit::getEditID()
{
    return EditID;
}

/* Инициализация статической переменной класса.
 * Статическая переменная класса должна инициализироваться в обязательном порядке
 * */
int dynamicEdit::ResEditID = 0;

