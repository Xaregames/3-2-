%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "y.tab.h"
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;}
"+" {return PLUS;}
"-" {return MINUS;}
\n  {return EOL;}
. {printf("Error:\n");}
%%
int yywrap(){
}
