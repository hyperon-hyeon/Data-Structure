#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

struct Node {
	int data;
	struct Node* next;
};

struct Node* top = NULL;
int count = 0;

int stackEmpty() {
	if (count <= 0) { return 1; }
	else { return 0; }
}

int stackFull() {
	if (count >= MAX_SIZE) { return 1; }
	else { return 0; }
}

void enStack(int num) {
	if (!stackFull()) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		if (temp == NULL) {
			printf("Memory allocation is failed\n");
			exit(1);
		}
	
		temp->data = num;
		temp->next = top;
		count++;
		
		top = temp;
	}
	else { printf("[Error] Stack is full \n"); }
}

void deStack() {
	if (!stackEmpty()) {
		struct Node* temp = top;
		int value = -1;

		if (count == 1) { 
			value = top->data;
			top = NULL;
		}
		else {
			value = top->data;
			top = top->next;
		}

		free(temp);
		count--;
		printf("%d Stack is deleted\n", value);
	}
	else { printf("[Error] Stack is empty\n"); }
}

void printStack() {
	printf("Current stack(top to bottom): ");
	if (top == NULL) { printf("None\n"); }
	else {
		struct Node* n = top;
		if (count == 1) {
			printf(" %d -> ", top->data);}
		else {
			while (n != NULL) {
				printf("%d -> ", n->data);
				n = n->next;
			}
		}
		printf("NULL\n");
	}
}

int main() {
	
	int menuNum = -1;
	int inputNum = -1;

	printf("[Menu] Quit - 0 / Insert - 1 / Delete - 2 / Print - 3\n");
	printf("Your choice: ");
	scanf_s("%d", &menuNum);

	while (menuNum != 0) {
		if (menuNum == 1) {
			printf("Press number to insert: ");
			scanf_s("%d", &inputNum);
			enStack(inputNum);
			printf("[Result] ");
			printStack();
		}
		else if (menuNum == 2) {
			deStack();
			printf("[Result] ");
			printStack();
		}
		else if (menuNum == 3) { printStack(); }
		else { printf("%d cannot work. Press another number\n", menuNum); }

		printf("\n[Menu] Quit - 0 / Insert - 1 / Delete - 2 / Print - 3\n");
		printf("Your choice: ");
		scanf_s("%d", &menuNum);
	}
	free(top);
	return 0;
}
