#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;


int queue_empty() {
	if (front <= -1) { return 1; }
	else { return 0; }
}

int queue_full() {
	
	if (rear >= MAX_SIZE - 1) { 
		return 1; 
	}
	else { return 0; }
}

void print_queue() {
	if (queue_empty()) { printf("Queue is empty!! \n"); }\
	else {
		printf("Queue:");
		if(front>rear && front!=0){printf(" None\n");}
		else{
			for (int i = front; i <= rear; i++) {
				printf(" %d", queue[i]);
			}
		//printf(" -> front: %d, rear: %d\n", front, rear);
		printf("\n");
		}
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
	else { printf("ERROR!! Queue is full!\n"); }
}

void dequeue() {
	if (front == rear+1 ) {
		front = -1;
		rear = -1;
	}
	if (!queue_empty()) {
		front++;
	}
	else { printf("ERROR!! Queue is empty\n"); }
}

int main() {
	int menu = -1;
	int enter = -1;
	int data = -1;
	printf("[Menu] Exit - 0 , Print - 1, Push - 2, Pop - 3\n");
	scanf_s("%d", &menu);
	
	while (menu != 0) {
		if (menu == 1) { print_queue(); }
		else if (menu == 2) {
			printf("Enter command: ");
			scanf_s("%d", &enter);
			for (int i = 0; i < enter; i++) {
				printf("Enter data: ");
				scanf_s("%d", &data);
				enqueue(data);
			}
		}
		else if (menu == 3) {
			dequeue();
		}
		else { printf("%d is not available!!\n", menu); }
		printf("\n[Menu] Exit - 0 , Print - 1, Push - 2, Pop - 3\n");
		scanf_s("%d", &menu);
	}
	return 0;
}