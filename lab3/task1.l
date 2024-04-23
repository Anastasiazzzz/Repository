/*
запуск файла в терминале:

lex task1.l
cc lex.yy.c -o task1 -ll
./task1

Ctrl+D для закрытия файла
*/


%{
#include <stdio.h>
%}

%%
[+-]?[0-9]+     printf("Целое число\n");

[a-zA-Z]+       printf("Строка\n");

[A-Za-z0-9]+    printf("Строка и целое число\n");

[ \t]+ ; // пропуск пробелов
%%