// Написать программу для генератора лексических анализаторов, выводящую в консоль переданный токен
// Получить результат работы программы для нескольких (не менее трёх) вариантов исходных данных

#include <stdio.h>
#include <string.h>

#define SIZE 20

typedef struct {
    int type;
    char value[SIZE];
} Token;

// Лексический анализатор
Token lexer (char input[]) {
    Token token;

    // исходные данные - слово
    if (strcmp(input, "token") == 0) { // сравнение строк
        token.type = 1; // обращение к переменной из структуры
        strcpy(token.value, "token"); // копируем строку в массив value
    }

    // исходные данные - число
    else if (strcmp(input, "789") == 0) {
        token.type = 2;
        strcpy(token.value, "789");
    }

    // исходные данные - символы
    else if (strcmp(input, "$/#") == 0) {
        token.type = 3;
        strcpy(token.value, "$/#");
    }

    else {
        token.type = 0;
        strcpy(token.value, "unknown");
    }

    return token;
}

int main() {
    char input[SIZE];
    Token token;

    printf("Введите данные: ");
    scanf("%s", input);

    token = lexer(input);

    if (token.type != 0) {
        printf("Значение токена: %s\n", token.value);
    }

    else {
        printf("%s\n", token.value);
    }

    return 0;
}