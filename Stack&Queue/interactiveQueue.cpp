#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front=-1, rear=-1, count=0;

int queueEmpty(){
    if (count<=0) return 1;
    else return 0;
}

int queueFull(){
    if (count>=MAX_SIZE) return 1;
    else return 0;
}

void enQueue(int num){
    if(!queueFull()){
        if (count==0) {
            front = 0;
            rear = 0;
            count++;
            queue[rear] = num;
        }
        else{
            rear++;
            count++;
            queue[rear%MAX_SIZE] = num;
        }
    }
    else { printf("[Error] Queue is full!\n"); }
}

void deQueue(){
    if (!queueEmpty()) { 
        front++; 
        count--;
    }
    else { printf("[Error] Queue is empty!\n"); }
}

void printQueue(){
    printf("Queue ->  ");
    if (queueEmpty()) { printf("None"); }
    else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf(" \n");
    
}

int main() {

    int menu = -1, inputNum = 0;
    printf("[Menu] Exit - 0 / Print - 1 / Add - 2 / Delete - 3\n");
    scanf_s("%d", &menu);

    while (menu != 0) {
        if (menu == 1) { printQueue(); }
        else if (menu == 2) {
            printf("Insert number: ");
            scanf_s("%d", &inputNum);
            enQueue(inputNum);
            printf("[Result] ");
            printQueue();
        }
        else if (menu == 3) {
            deQueue();
            printf("[Result] ");
            printQueue();
        }
        else { printf("[Error] %d is not available\n", menu); }

        printf("\n[Menu] Exit - 0 / Print - 1 / Add - 2 / Delete - 3\n");
        scanf_s("%d", &menu);
    }
    return 0;
}