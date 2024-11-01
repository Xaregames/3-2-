#include <stdio.h>
#include <stdlib.h>


struct stek
{   
    int number;
    struct stek* nextNumber;
    
};

struct stek* push(struct stek* stek){
    int num;
    printf("Введите значение которое хотите добавить:\t");
    scanf("%d", &num);
    
    struct stek* top = malloc(sizeof(struct stek)); 
    
    top->number = num;
    top->nextNumber = stek;
    return top;
    
}

struct stek* push2(struct stek* stek, int num){
    
    struct stek* top = malloc(sizeof(struct stek)); 
    
    top->number = num;
    top->nextNumber = stek;
    return top;
    
}


void printStruct(struct stek* stek){
    struct stek* top = stek;
    
    while(top!= NULL){
        printf("%d\t",top->number);
        top = top->nextNumber;
    }
}


struct stek* pop(struct stek* stek,int num){
    
    int d_one;
    struct stek* dopStek = NULL;
    struct stek* top = stek;
    printf("Введите элемент который хотите удалить:\t");
    scanf("%d", &d_one);
    int d_two = d_one;
    
    while(d_two != num){
        
        dopStek = push2(dopStek,top->number);
        top = top->nextNumber;
        num--;
    }
    top = top->nextNumber;
    while(dopStek!=NULL){
        top = push2(top, dopStek->number);
        dopStek = dopStek->nextNumber;
    }
    
    free(stek);
    free(dopStek);
    return top;
}









int main()
{
    struct stek* stek = NULL;
    int id = 0;
    int a;
    
    
    
    
    while (a != 5){
        printf("Элементов в стеке:%d\n", id);
        printf("1)Добавить элемент в стек\n");
        printf("2)Удалить элемент из стека\n");
        printf("3)Просмотр всех элементов стека\n");
        printf("4)Просмотр вверхнего значения стека\n");
        printf("5)Выход\n");
        
        scanf("%d",&a);
        switch (a){
        case 1:
            if(id < 5){
                id++;
                stek = push(stek);
                break;
            }
            else{
                printf("Стек заполнен! Очистите стек для добавления нового значения!\n");
                break;
            }
        case 2:
            stek = pop(stek,id);
            id--;
            break;
        case 3:
            printStruct(stek);
            break;
        case 4: 
            printf("Вверхнее значение стека:\t%d\n",stek->number);
            break;
        case 5: 
            break;        
        
        }
    }
    
 
    
    
    return 0;
}
