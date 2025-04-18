#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Node {
	int data;
	Node* next;
};

Node* top=NULL;
int count = 0;

int stackFull(){
    if (count >= MAX_SIZE) return 1;
    else return 0;
}

int stackEmpty(){
    if (count <= 0) return 1;
    else return 0;
}

void enStack(int num){
    if (!stackFull()) {
        Node* temp = (Node*)malloc(sizeof(Node));
				if (temp == NULL) {
					printf("[Error] Memory allocation failed!\n");
					return;
			}
        temp->data = num;
        temp->next = top;
        top = temp;
        count++;
    }
    else printf("[Error] Stack is full!\n");
}

void deStack(){
    if (!stackEmpty()) {
        Node* temp = top;
        top = top->next;
        count--;
        free(temp);
    }
    else printf("[Error] Stack is empty!\n");
}

void printStack() {
    printf("Stack ->  ");

    if (!stackEmpty()) {
        Node* n = top;
        for (int i = 0; i < count; i++) {
            printf(" %d -", n->data);
            n = n->next;
        }
    }
    printf(" None\n");
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
    free(top);
    return 0;
}