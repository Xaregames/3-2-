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
    for (int i = 0; i < 256; i++) {
        if(isdigit(text[i])){
            stek = push(stek,atoi(text[i]));
        }
        else{
            int operation = (text[i] == '+') ? 1 :
                          ((text[i] == '-') ? 2 :
                              ((text[i] == '*') ? 3 :
                                  ((text[i] == '/') ? 4 : 0)));
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
}




int main(){
    struct stek *stek = NULL;
    char *text[256];
    
    FILE *file = fopen("text.txt",'r');
    
    fscanf(text,256,file);
    
    
        
    
    
    return 0;
}
