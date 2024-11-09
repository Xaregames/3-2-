#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


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


struct stek* pop(struct stek* stek){
    struct stek* top ;
    top = stek->nextNumber;
    free(stek);
    return top;
}


struct stek* answer(struct stek  *stek,char text, int k){

    if(isdigit(text)){
        if(k == 0){
            stek = push(stek,atoi(&text));
        }
        else{
            stek->number = stek->number * pow(10,k) + atoi(&text);
        }
    }
    else{
        int operation = (text == '+') ? 1 :
                      ((text == '-') ? 2 :
                          ((text == '*') ? 3 :
                              ((text == '/') ? 4 : 0)));
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
    return stek;
    
}

void printStruct(struct stek* stek){
    struct stek* top = stek;
    
    while(top!= NULL){
        printf("%d\t",top->number);
        top = top->nextNumber;
    }
}




int main(){
    struct stek *stek = NULL;
    char text[20];
    char ch[256];
    FILE *file = fopen("text.txt","r");

    
    while((fscanf(file,"%s", text))!=EOF)
    {
        int  k = 0; // значение для того чтобы определять скольки значное число
        for (int i = 0; i < 20; i++) {
            printf("%c", text[i]);
            stek = answer(stek,text[i],k);
            k++;
        }
        printf(" \n");
        
    }
    printStruct(stek);
    
    
    return 0;
}
