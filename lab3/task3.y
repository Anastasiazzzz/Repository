/*
запуск файла в терминале:

bison -d task3.y
lex task3.l
cc lex.yy.c task3.tab.c -o task3
./task3

Ctrl+D для закрытия файла
*/


%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task3.tab.h"

int yylex(void); // лексический анализ входного потока и генерация токенов

void yyerror(const char *str)
{
    fprintf(stderr, "Error: %s\n", str);
}

int yywrap()
{
    return 1;
}

int main()
{
    yyparse();
}

%}

%token NUM
%token ADD SUB MUL DIV
%token LEFTBRACE RIGHTBRACE
%token EXIT
%token EOL

%%

commands:
| commands command
;

command: exp
| EOL { printf("\n"); }
| EXIT { printf("End\n"); exit(0); }
;

exp: factor
| exp ADD factor { printf("+"); }
| exp SUB factor { printf("-"); }
;

factor: term
| factor MUL term { printf("*"); }
| factor DIV term { printf("/"); }
;

term: NUM { printf("%d", $1); }
| LEFTBRACE exp RIGHTBRACE { $$ = $2; }
;

%%