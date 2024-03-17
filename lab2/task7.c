/*Написать программу, вычисляющую значение выражения, записанного в постфиксной записи, считываемого из входного файла. Считать, что выражение может содержать только цифры и знаки «+», «-», «*» и «/».*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data)
{
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    }
    else {
        top++;
        stack[top] = data;
    }
}


int pop()
{
    if (top < 0) {
        printf("Stack Underflow\n"); // проверка пустой ли стек
        return -1;
    }
    else {
        int data = stack[top];
        top--;
        return data;
    }
}


int evaluate(char expr[])
{
    int i = 0, value;

    for (i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) { // проверка является ли цифрой
            push(expr[i] - '0'); // помещение в стек
        }
        else {
            int num2 = pop();
            
            int num1 = pop();

            printf("%c", expr[i]);
            switch (expr[i]) {
                case '+':
                    value = num1 + num2;
                    break;
                case '-':
                    value = num1 - num2;
                    break;
                case '*':
                    value = num1 * num2;
                    break;
                case '/':
                    value = num1 / num2;
                    break;
                default:
                    printf("Invalid expression\n");
                    exit(1);
            }
            push(value);
        }
    }
    return pop();
}


int main()
{
    char expr[MAX_SIZE];

    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fgets(expr, MAX_SIZE, file); // чтение строки из файла и сохранение в expr

    fclose(file);

    int result = evaluate(expr);
    printf("Result: %d\n", result);

    return 0;
}
