#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


char text[256];
int i;
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
        printf("%c",top->number);
        top = top->nextNumber;
    }
}

bool digit(char ch){
    if(ch != '+' && ch != '-' && ch !='*' && ch != '/'){
        return true;
    }
    else{
        
        return false;
    }
}

char *add(char* text, char ch){
    
}




struct stek* answer(struct stek* stek,char ch,int priority){
    struct stek* top = stek;
    if(top == NULL){
        top =push(top,ch,priority);
        return top;
    }
    else if(priority > stek->priority){
        
        top = push(top,ch,priority);

        return top;
    }
    else if(priority = top->priority){
        
        text[i] = top->number;
        top = pop(top);
        top = push(top,ch,priority);
        return top;
    }
    else if(priority < top->priority){
        text[i] = top->number;
        i++;
        top = pop(top);
        return answer(top,ch,priority);
    }
    
}

int main(){
  
  struct stek* stek = NULL;
  char ch[256];
  
  
  fgets(ch,256,stdin);
  
  int priority = 0;
  for (i = 0; i < 256; i++) {
      if(digit(ch[i])){
          text[i] = ch[i];
          printf("%c\n", text[i]);
          continue;
      }
        
      else if(ch[i] == 40){
            priority += 2;
            continue;
      }
      else if(ch[i] == 41){
            priority -= 2;
            continue;
      }
      if(ch[i] == '+' || ch[i] == '-' ){
        priority = 1;
          
      }
      else if( ch[i] =='*' || ch[i] == '/'){
        priority = 2;
      }
    
    
    stek = answer(stek,ch[i],priority);
    printStruct(stek);
    
     
  } 
  
  
  
  for (int i = 0; i < 256 && stek != NULL; i++) {
        if (i < 255) { // Проверяем, достигли ли конца строки или списка
            printf("%c", text[i]);
        } else{
            printStruct(stek);
        }
    }
}
