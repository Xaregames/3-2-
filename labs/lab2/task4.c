#include <stdio.h>
#include <stdlib.h> // Для функции rand 
#include <time.h>
#include <math.h>


void massWritingInFile(float mass[], int sizeMass){
    
    FILE *fileWriting = fopen("task2.txt", "w");
    
    
  
    
    
    int sizeOneElementMass = sizeof(mass[0]);
    
    for (int i = 0; i < sizeMass; i++) {
        fprintf(fileWriting, "%.2f\t",mass[i]);
    }
    fclose(fileWriting);
   
}


void swap(float *var1, float *var2){
    
        float var3 = *var1;
        *var1 = *var2;
        *var2 = var3;
    
}
void sortMass(float mass[], int sizeMass){
    int testMassSort = 0;

    for (int i = 0; i < sizeMass-1;) {
        if(mass[i] > mass[i+1]){
            swap(&mass[i],&mass[i+1]);
            if(i!=0){
                i--;
            }
        }
        else i++;
    }
    
    
    
}


int main(int argc, char *argv[])
{
    
    
    srand(time(NULL)); // для того чтобы при каждом запуске программы числа менялись
    
    float arg1, arg2;
    
    scanf("%f%f", &arg1, &arg2);
    
    int sizeMass = atoi(argv[1]); // atoi функция которая преобразует тип char в int
    
    float massRand[atoi(argv[1])]; // Берем 1 потому что по умолчанию при передаче аргумента в функцию мейн стоит ./0
    

    if(arg1 > arg2){
        for (int i = 0; i < sizeMass; i++) { // присваиваем псевдо-случайное значение каждому элементу массива с последующим ввыводом в консоль
        massRand[i] = (float)rand()/RAND_MAX*(arg1-arg2) + arg2; 
        }
    }
    else if(arg2 > arg1){
        for (int i = 0; i < sizeMass; i++) { // присваиваем псевдо-случайное значение каждому элементу массива с последующим ввыводом в консоль
        massRand[i] = (float)rand()/RAND_MAX*(arg2-arg1) + arg1; 
        }
    }
    else{
        printf("Промежуток равен 0!");
    }
    for (int i = 0; i < sizeMass; i++) { // присваиваем псевдо-случайное значение каждому элементу массива с последующим ввыводом в консоль
        printf("%.2f\t", massRand[i]);
    }
    
    printf("\n");
    
    sortMass(massRand, sizeMass);
    
    massWritingInFile(massRand, sizeMass);
    
    
    
    
    return 0;
}
