#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Максимальный размер стека

int stack[MAX];
int top = -1;

// Функция для добавления элемента в стек
void push(int value) {
    if (top == MAX - 1) {
        printf("Стек переполнен!\n");
    } else {
        top++;
        stack[top] = value;
        printf("Значение %d добавлено в стек.\n", value);
    }
}

// Функция для извлечения элемента из стека
int pop() {
    if (top == -1) {
        printf("Стек пуст!\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        printf("Значение %d извлечено из стека.\n", value);
        return value;
    }
}

// Функция для просмотра верхнего элемента стека
int peek() {
    if (top == -1) {
        printf("Стек пуст!\n");
        return -1;
    } else {
        printf("Верхнее значение стека: %d\n", stack[top]);
        return stack[top];
    }
}

// Функция для проверки состояния стека (пуст или полон)
void checkStackState() {
    if (top == -1) {
        printf("Стек пуст!\n");
    } else if (top == MAX - 1) {
        printf("Стек полон!\n");
    } else {
        printf("В стеке имеются элементы.\n");
    }
}

int main() {
    // Пример работы с функциями стека
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);  // Заполнение стека
    push(60);  // Переполнение стека

    peek();    // Проверка верхнего элемента

    pop();     // Извлечение элемента
    pop();

    peek();    // Проверка верхнего элемента после извлечения

    pop();
    pop();
    pop();     // Извлечение до опустошения стека
    pop();     // Попытка извлечения из пустого стека

    checkStackState();  // Проверка состояния стека

    return 0;
}
