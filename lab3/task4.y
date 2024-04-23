/*
запуск файла в терминале:

bison -d task4.y
lex task4.l
cc lex.yy.c task4.tab.c -o task4
./task4

Ctrl+D для закрытия файла
*/


%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task4.tab.h"

int yylex(void);

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

%union // объявление объединения для определения возможных типов значений
{
    double val;
}

%token REALNUM
%token ADD SUB MUL DIV
%token LEFTBRACE RIGHTBRACE
%token EXIT
%token EOL

%type <val> REALNUM // объявление типов симантических значений
%type <val> exp
%type <val> term
%type <val> factor

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

term: REALNUM { printf("%f", $1); }
| LEFTBRACE exp RIGHTBRACE { $$ = $2; }
;

%%