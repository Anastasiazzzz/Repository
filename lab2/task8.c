/*Написать программу, реализующую перевод инфиксной записи арифметического выражения в постфиксную. Исходное арифметическое выражение состоит из цифр, знаков «+», «-», «*», «/» и скобок.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Stack Underflow\n");
        return -1;
    }
    else {
        int data = stack[top];
        top--;
        return data;
    }
}


int isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}


int priorityOperator(char symbol)
{
    if (symbol == '+' || symbol == '-') {
        return 1;
    }
    else if (symbol == '*' || symbol == '/') {
        return 2;
    }
    else {
        return 0;
    }
}


void infixToPostfix(char *infix, char *postfix)
{
    int i = 0; j = 0;

    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (isdigit(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (top != -1 && data[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
            //push(symbol);
        }
        else if (isOperator(symbol)) {
            while (top != -1 && priorityOperator(data[top]) >= priorityOperator(symbol)) {
                postfix[j++] = pop();
            }
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}


int main()
{
char infix[MAX_SIZE], postfix[MAX_SIZE];

printf("Enter the infix expression: ");
fgets(infix, MAX_SIZE, stdin); // чтение введённой строки и сохранение в infix

infixToPostfix(infix, postfix);

printf("Postfix expression: %s\n", postfix);
return 0;
}