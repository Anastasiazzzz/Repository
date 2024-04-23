/*
запуск файла в терминале:

bison -d task2.y
lex task2.l
cc lex.yy.c task2.tab.c -o task2
./task2

Ctrl+D для закрытия файла
*/


%{
#include <stdio.h>
#include <string.h>
#include "task2.tab.h"

int yylex(void); // лексический анализ входного потока и генерация токенов

void yyerror(const char *str)
{
    fprintf(stderr, "Error %s\n", str); // вывод сообщения об ошибке при её обнаружении
}

int yywrap()
{
    return 1;   // достигнут конец файла
}

int main(int argc, char **argv)
{
    yyparse(); // запуск синтаксического анализа
}

%}

%token NUM    // определение используемых токенов
%token ADD SUB ABS
%token EOL

%%

calclist: /* nothing */     // пустой вход, программа завершится
| calclist exp EOL { printf("= %d\n", $2); }
;

exp: factor
    | exp ADD factor { $$ = $1 + $3; }
    | exp SUB factor { $$ = $1 - $3; }
;

factor: term
    | factor ADD term { $$ = $1 + $3; }
    | factor SUB term { $$ = $1 - $3; }

term: NUM
    | ABS term { $$ = $2 >=  0? $2 : - $2; }
;

%%