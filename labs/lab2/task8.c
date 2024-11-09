#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


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
        printf("%d\t",top->number);
        top = top->nextNumber;
    }
}

bool digit(char ch){
    if(ch != 42 || ch != 43 || ch !=45 || ch || 47){
        return true;
    }
    else{
        
        return false;
    }
}

char *add(char* text, char ch){
    
}


struct stek* answer(struct stek* stek,char ch,char* text,int priority){
    struct stek* top = stek;
    if(top == NULL){
        top =push(top,ch,priority);
        return top;
    }
    else if(priority > stek->priority){
        top = push(top,ch,priority);
        return stek;
    }
    else if(priority = top->priority){
        char addChar = top->number;
        top = pop(top);
        top = push(top,ch,priority);
        return stek;
    }
    else if(priority < top->priority){
        top = pop(top);
        return answer(top,ch,text,priority);
    }
    
}

int main(){
  
  struct stek* stek = NULL;
  char ch[256];
  
  char text[256];
  fgets(ch,256,stdin);
  
  int priority = 0;
  for (int i = 0; i < 256; i++) {
      if(digit(ch[i])){
          text[i] = ch[i];
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
    
    stek = answer(stek,ch[i],text,priority);
    
     
  } 
  
  for (int i = 0; i < 256; i++) {
      printf("%c", text[i]);
  }
  
}
