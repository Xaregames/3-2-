#include <stdio.h>
#include <stdlib.h> // Для функции rand 
#include <time.h>;

int main()
{
    srand(time(NULL)); // для того чтобы при каждом запуске программы числа менялись
    
    int sizeMass = rand()%(101); // псевдо-случайное определение размера массива от 0 до 100
    
    int massRand[sizeMass];
    
    printf("%d\n", sizeMass);
    
    for (int i = 0; i < sizeMass; i++) { // присваиваем псевдо-случайное значение каждому элементу массива с последующим ввыводом в консоль
        massRand[i] = rand()%(1000); // от 0 до 1000
        printf("%d\t", massRand[i]);
    }
    
    

    return 0;
}
