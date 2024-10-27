%{
#include <stdio.h>
%}

%%



%%

int main(void) {
    printf("Введите токен. Нажмите Ctrl+D (или Ctrl+Z в Windows) для завершения:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
