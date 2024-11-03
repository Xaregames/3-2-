/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct stek{
    int number;
    struct stek *nextNumber;
};


struct stek* push(struct stek* stek, int num){
    
    struct stek* top = malloc(sizeof(struct stek)); 
    
    top->number = num;
    top->nextNumber = stek;
    return top;
    
}

struct stek answer(struct stek  *stek,char *text){

    if(isdigit(atoi(text))){
        stek = push(stek,atoi(text));
    }
    else{
        int operation = (text[0] == '+') ? 1 :
                      ((text[0] == '-') ? 2 :
                          ((text[0] == '*') ? 3 :
                              ((text[0] == '/') ? 4 : 0)));
        switch (operation){
            case 1:
                stek->nextNumber->number = stek->nextNumber->number + stek->number;
                stek = stek->nextNumber;
                break;
            case 2:
                stek->nextNumber->number = stek->nextNumber->number - stek->number;
                stek = stek->nextNumber;
            break;
            case 3:
                stek->nextNumber->number = stek->nextNumber->number * stek->number;
                stek = stek->nextNumber;
                break;
            case 4:
                stek->nextNumber->number = stek->nextNumber->number / stek->number;
                stek = stek->nextNumber;
                break;
        }
    }
    
}




int main(){
    struct stek *stek = NULL;
    char text[20];
    char ch[256];
    FILE *file = fopen("text.txt","r");

    
    while((fscanf(file,"%s ", text))!=EOF)
    {
        
        
    }
    
    for (int i = 0; i < 20; i++) {
            printf("%c\n", text[i]);
        }
    
    
    return 0;
}

