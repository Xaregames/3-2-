


%{
#include "yac.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
%}

%% 

[0-9]+\.[0-9]+    { yylval.d= atof(yytext); return NUMBER; }  // Вещественные числа
[ \t]        ; // Игнорируем пробелы
\n           { return 0; }
"("          { return '('; }
")"          { return ')'; }
"+"          { return '+'; }
"-"          { return '-'; }
"*"          { return '*'; }
"/"          { return '/'; }
.            { printf("Неизвестный символ: %s\n", yytext); }

%% 

int yywrap() {
    return 1;
}
