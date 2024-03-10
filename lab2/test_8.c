#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void push(struct Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = value;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int precedence(char symbol) {
    if(symbol == '+' || symbol == '-')
        return 1;
    if(symbol == '*' || symbol == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    struct Stack s;
    s.top = -1;
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char token = infix[i];
        
        if (isdigit(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&s, token);
        } else if (token == ')') {
            while (s.top != -1 && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else if (isOperator(token)) {
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(token)) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
        i++;
    }
    
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    return 0;
}