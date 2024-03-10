/*Написать программу, в которой реализовать набор функций по работе со стеком:
Организовать хранение стека в памяти;
Реализовать добавление значения в стек;
Реализовать извлечение значения из стека;
Реализовать просмотр верхнего значения стека;
Учесть при работе возможность переполнения стека.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack* next;
} OBJ;


OBJ* push(OBJ* top, int data) // Фун-я добавления новых значений в стек
{
    OBJ* ptr = malloc(sizeof(OBJ)); // выделение памяти под объект в стеке (динамически)
    ptr->data = data;
    ptr->next = top; // указание на следующий объект в стеке
    return ptr;
}


OBJ* pop(OBJ* top) // Фун-я извлечения значений из стека
{
    if (top == NULL) { // проверка на наличие верхнего элемента
        return top;
    }

    printf("Deleted: %d\n", top->data);
    OBJ* ptr_next = top->next; // взятие адреса пердыдущего объекта
    free(top);

    return ptr_next;
}


void show(const OBJ* top) // Фун-я росмотра верхнего значения стека
{
    const OBJ* temp = top;
    printf("Top value of the stack: %d\n", temp->data);
}


void freeStack(OBJ* top) // Фун-я освобождения выделенной памяти
{
    OBJ* temp = top;
    while (temp) {
        OBJ* ptr_next = temp->next;
        free(temp);
        temp = ptr_next;

    }
}


int main(void)
{
    OBJ* top = NULL; // указние, что стек пуст

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);

    show(top);

    while (top) {
        top = pop(top);
    }

    freeStack(top);

    return 0;
}