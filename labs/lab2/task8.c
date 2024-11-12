#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


char text[256];
int i,k = 0;
struct stek{
    char number;
    int priority;
    struct stek *nextNumber;
};


struct stekOper{
    
};


struct stek* push(struct stek* stek, char num, int priority){
    
    struct stek* top = malloc(sizeof(struct stek)); 
    
    top->number = num;
    top->nextNumber = stek;
    top->priority = priority;
    return top;
    
}


struct stek* pop(struct stek* stek){
    struct stek* top ;
    top = stek->nextNumber;
    free(stek);
    return top;
}



void printStruct(struct stek* stek){
    struct stek* top = stek;
    
    while(top!= NULL){
        printf("%c\t%d",top->number,top->priority);
        top = top->nextNumber;
    }
    printf("\n");
}

bool digit(char ch){
    if(ch != '+' && ch != '-' && ch !='*' && ch != '/'){
        return true;
    }
    else{
        
        return false;
    }
}






struct stek* answer(struct stek* stek,char ch,int priority){
    struct stek* top = stek;
    //printStruct(top);
    if(top == NULL){
        top =push(top,ch,priority);
        return top;
    }
    else if(priority > stek->priority){
        
        top = push(top,ch,priority);
        
        return top;
    }
    else if(priority = top->priority){
        
        text[k] = top->number;
        k++;
        top = pop(top);
        top = push(top,ch,priority);
        return top;
    }
    else if(priority < top->priority){
        text[k] = top->number;
        k++;
        top = pop(top);
        printStruct(top);
        return answer(top,ch,priority);
    }
    
    
}

int main(){
  
  struct stek* stek = NULL;
  char ch[256];
  
  fgets(ch,256,stdin);
  
  int priority = 0;
  int skobky = 0;
  for (i = 0; i < 256; i++) {
      if(digit(ch[i]) && ch[i] != 40 && ch[i] != 41){
          text[k] = ch[i];
          k++;
          //printf("X%c\n", text[k-1]);
          continue;
      }
        
      else if(ch[i] == 40){
            skobky += 2;
            printf("TET");
            continue;
      }
      else if(ch[i] == 41){
            skobky -= 2;
            continue;
      }
      if(ch[i] == '+' || ch[i] == '-' ){
        priority = 1 + skobky;
        //printf("TUT%c\t%d",ch[i],priority);
          
      }
      else if( ch[i] =='*' || ch[i] == '/'){
        priority = 2 + skobky;
        //printf("%c\t%d",ch[i],priority);
      }
    
    printf("TUT%c\t%d",ch[i],priority);
    stek = answer(stek,ch[i],priority);
    //printStruct(stek);
    
    
    
    
  } 
  

  
    for (int i = strlen(text); stek != NULL; i++) {
        
        text[i] = stek->number;
        stek = pop(stek);
        
    }
    
    
    for (int i = 0; i < strlen(text) ; i++) {
        
        if(text[i] == 10){
            continue;
        }
        
        printf("%c",text[i]);
    }

    
}
