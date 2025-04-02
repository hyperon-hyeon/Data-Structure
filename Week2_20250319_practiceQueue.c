#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int queue_full() {
	if (front == rear && !queue_empty()) {
		int temp = queue[rear];
		front = 0;
		rear = 0;
		queue[front] = temp;
	}
	if (rear >= MAX_SIZE - 1) { 
		return 1; 
	}
	else { return 0; }
}

int queue_empty() {
	if (front <= -1) { return 1; }
	else { return 0; }
}

void print_queue() {
	if (queue_empty()) { printf("Stack is empty!! \n"); }
	else if (queue_full()) { print("Stack is full!!\n"); }
	else {
		printf("Stack:");
		for (int i = front; i <= rear; i++) {
			printf(" %d", queue[i]);
		}
		printf("\n");
	}
}

void enqueue(int num) {
	if (front==-1 && rear==-1) {
		front++;
		rear++;
		queue[rear] = num;
	}
	else if (!queue_full()) {
		rear++;
		queue[rear] = num;
	}
	else { printf("ERROR!!\n"); }
}

void dequeue() {
	if (!queue_empty) {
		front++;
	}
	else { printf("ERROR!!\n"); }
}

int main() {
	int menu = -1;
	int enter = -1;
	int data = -1;
	printf("Menu - 0: Exit, 1: Print, 2:  Push, 3: Pop");
	scanf_s("%d", &menu);
	
	while (menu != 0) {
		if (menu == 1) { print_queue(); }
		else if (menu == 2) {
			printf("Enter command: ");
			scanf_s("%d", &enter);
			for (int i = 0; i <= enter; i++) {
				printf("Enter data: ");
				scanf_s("%d", &data);
				enqueue(data);
			}
		}
		else if (menu == 3) {
			dequeue();
		}
		else { printf("%d is not available!!\n", menu); }
		printf("Menu - 0: Exit, 1: Print, 2:  Push, 3: Pop");
		scanf_s("%d", &menu);
	}
	print_queue();
	return 0;
}