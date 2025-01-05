%{
#include "yac.tab.h"
#include <stdlib.h>
%}

%% 
[0-9]+        { yylval = atoi(yytext); return NUMBER; }
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
