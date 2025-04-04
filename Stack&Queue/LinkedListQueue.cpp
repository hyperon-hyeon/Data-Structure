#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

struct Node{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int count = 0;

int queue_full() {
	if (count >= MAX_SIZE) {
		printf("[ERROR]  Queue is full\n");
		return 1;
	}
	return 0;
}

int queue_empty() {
	if (count <= 0) {
		printf("[ERROR] Queue is empty\n");
		return 1;
	}
	return 0;
}

void enqueue(int num) {

	if (!queue_full()) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		if (temp == NULL) {
			printf("Memory allocation is failed\n");
			exit(1);
		}
		temp->data = num;
		temp->next = NULL;

		if (front == NULL && rear == NULL) {
			front = temp;
			rear = temp;
			count = 1;
			return;
		}
		else {
			rear->next = temp;
			rear = temp;
			count++;
			return;
		}
	}
	else {printf("[ERROR] Queue is full\n");}
}

void dequeue() {
	if (!queue_empty()) {
		struct Node* temp = front;
		int value;

		if (count == 1) {rear = NULL;}

		value = front->data;
		front = front->next;
			
		free(temp);
		count--;
		printf("%d value node is deleted\n",value);
	}else {printf("[ERROR] Queue is empty\n");}
}

void printQueue() {
	printf("Current Node: ");
	if (front==NULL) { printf("None"); }
	else {
		struct Node* n = front;	
		if (count == 1) { printf("%d", n->data); }
		else {
			printf("%d", n->data);
			n = n->next;
			for (int i = 0; i < count-1; i++) {
				printf(" -> %d", n->data);
				n=n->next;
			}
			free(n);
		}
	}
	printf("\n");
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
			enqueue(inputNum);
			printf("[Result] ");
			printQueue();
		}
		else if (menuNum == 2) {
			dequeue(); 
			printf("[Result] ");
			printQueue();
		}
		else if (menuNum == 3) { printQueue(); }
		else { printf("%d cannot work. Press another number", menuNum); }

		printf("\n[Menu] Quit - 0 / Insert - 1 / Delete - 2 / Print - 3\n");
		printf("Your choice: ");
		scanf_s("%d", &menuNum);
	}
	free(front);
	free(rear);
	return 0;
}