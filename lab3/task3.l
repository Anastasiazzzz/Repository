%{
#include <stdio.h>
#include <string.h>
#include "task3.tab.h"
%}

%%
[0-9]+  yylval=atoi(yytext); return NUM; // перевод из строки в число и перезапись
"+"     return ADD;
"-"     return SUB;
"*"     return MUL;
"/"     return DIV;
"("     return LEFTBRACE;
")"     return RIGHTBRACE;
"exit"  return EXIT;
"\n"    return EOL;
[\t]+ ;
%%