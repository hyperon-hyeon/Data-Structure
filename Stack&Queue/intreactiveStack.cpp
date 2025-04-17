#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int stackEmpty() {
    if (top < 0) return 1;
    else return 0;
}

int stackFull() {
    if (top >= MAX_SIZE - 1) return -1;
    else return 0;
}

void enStack(int num) {
    if (!stackFull()) {
        top++;
        stack[top] = num;
    }
    else { printf("[Error] Stack is full!\n"); }
}

void deStack() {
    if (!stackEmpty()) top--;
    else { printf("[Error] Stacl is empty!\n"); }
}

void printStack() {
    printf("Stack ->  ");
    if (stackEmpty()) { printf("None"); }
    else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main() {

    int menu = -1, inputNum = 0;
    printf("[Menu] Exit - 0 / Print - 1 / Add - 2 / Delete - 3\n");
    scanf_s("%d", &menu);

    while (menu != 0) {
        if (menu == 1) { printStack(); }
        else if (menu == 2) {
            printf("Insert number: ");
            scanf_s("%d", &inputNum);
            enStack(inputNum);
            printf("[Result] ");
            printStack();
        }
        else if (menu == 3) {
            deStack();
            printf("[Result] ");
            printStack();
        }
        else { printf("[Error] %d is not available\n", menu); }

        printf("\n[Menu] Exit - 0 / Print - 1 / Add - 2 / Delete - 3\n");
        scanf_s("%d", &menu);
    }
    return 0;
}