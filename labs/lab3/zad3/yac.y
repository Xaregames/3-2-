%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
expr: expr '+' term { printf("+ "); }
    | expr '-' term { printf("- "); }
    | term
    ;

term: term '*' factor {  printf("* "); }
    | term '/' factor {  printf("/ "); }
    | factor
    ;

factor: '(' expr ')' {}
       | NUMBER { printf("%d ", $1); }
       ;

%% 

void yyerror(const char *s) {
    fprintf(stderr, "Ошибка: %s\n", s);
}

int main(void) {
    printf("Введите выражение:\n");
    while (yyparse()) {
        printf("Введите выражение:\n");
    }
    return 0;
}
