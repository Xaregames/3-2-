#include <stdio.h>
#include <stdlib.h> // Для функции rand 
#include <time.h>


int main(int argc, char *argv[])
{
    
    
    srand(time(NULL)); // для того чтобы при каждом запуске программы числа менялись
    
    int sizeMass = atoi(argv[1]); // atoi функция которая преобразует тип char в int
    
    float massRand[atoi(argv[1])]; // Берем 1 потому что по умолчанию при передаче аргумента в функцию мейн стоит ./0
    

    
    for (int i = 0; i < sizeMass; i++) { // присваиваем псевдо-случайное значение каждому элементу массива с последующим ввыводом в консоль
        massRand[i] = (float)rand()/RAND_MAX; 
        printf("%.2f\t", massRand[i]);
    }
    
    
    
    

    return 0;
}
