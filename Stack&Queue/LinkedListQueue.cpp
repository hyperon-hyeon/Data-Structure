#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Node {
	int data;
	Node* next;
};

int count = 0;
Node* front = NULL;
Node* rear = NULL;

int queueFull(){
    if (count >= MAX_SIZE) return 1;
    else return 0;
}

int queueEmpty(){
    if (count <= 0) return 1;
    else return 0;
}

void enQueue(int num){
    if (!queueFull()) {
        Node* temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("[Error] Memory allocation failed!\n");
            return;
        }

        temp->data = num;
        temp->next = NULL;

        if (count == 0) {
            front = temp;
            rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }

        count++;

    }
    else printf("[Error] Queue is full!\n");
}

void deQueue(){
    if (!queueEmpty()) {
        Node* temp = front;
        front = temp->next;
        count--;
        free(temp);
    }
    else { printf("[Error] Queue is empty!\n"); }
}

void printQueue(){
    printf("Queue (front-rear) ->  ");
    if (!queueEmpty()) {
        Node* n = front;
        for (int i = 0; i < count; i++) {
            printf(" %d ", n->data);
            n = n->next;
            if (n != NULL) printf("-");
        }
    }
    else printf("None\n");
    printf("\n");
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