%{
#include <stdio.h>
#include <string.h>
#include "task2.tab.h"
%}

%%
[0-9]+      yylval=atoi(yytext); return NUM; // перевод из строки в число и перезапись
"+"         return ADD; // addition, тип токена
"-"         return SUB; // subtration
"|"         return ABS;
\n          return EOL; // пропуск конца строки
[ \t]+ ;                // пропуск пробелов
%%