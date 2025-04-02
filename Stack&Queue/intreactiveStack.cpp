#include <stdio.h>
#define MAX_SIZE 10

int top = -1;
int stack[MAX_SIZE];

int stack_empty() {
	if (top < 0) {	return 1;}
	else { return 0; }
}

int stack_full() {
	if (top >= MAX_SIZE-1) { return 1; }
	else { return 0; }
}

void enStack(int num) {
	if (!stack_full()) {
		top++;
		stack[top] = num;
	}
	else { printf("[Error] Stack is full\n"); }
}

void deStack() {
	if (!stack_empty()) { top--; }
	else { printf("[Error] Stack is empty\n"); }
}

void printStack() {
	printf("Current Stack: ");
	if (!stack_empty()) {
		for (int i = 0; i <= top; i++) {
			printf("%d ", stack[i]);
		}
	} else { printf("None"); }
	printf("\n");
}

int main() {
	int menuNum = -1;
	int insertNum = -1;

	printf("[Menu]: Quit - 0 / Insert - 1 / Delete - 2 / Print - 3\n");
	printf("Press your choice: ");
	scanf_s("%d", &menuNum);

	while (menuNum != 0) {
		if (menuNum == 1) {
			printf("Press the number to Insert: ");
			scanf_s("%d",&insertNum);
			enStack(insertNum);
			printf("[Result] ");
			printStack();
		}
		else if (menuNum == 2) {
			deStack();
			printf("[Result] ");
			printStack();
		}
		else if (menuNum == 3) { printStack(); }
		else { printf("Press another number"); }

		printf("\n[Menu]: Quit - 0 / Insert - 1 / Delete - 2 / Print - 3\n");
		printf("Press your choice: ");
		scanf_s("%d", &menuNum);
	}
}