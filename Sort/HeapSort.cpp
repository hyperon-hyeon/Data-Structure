#include <stdio.h>

void MinHeap(int array[], int size, int i) {
	int smallest = i;
	int leftChild = i * 2 + 1;
	int rightChild = i * 2 + 2;

	if (leftChild < size && array[leftChild] < array[smallest]) {
		smallest = leftChild;
	}
	if (rightChild < size && array[rightChild] < array[smallest]) {
		smallest = rightChild;
	}

	if (smallest != i) {
		int temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;

		MinHeap(array, size, smallest);
	}
}

void RepeatMinHeap(int array[], int size) {
	for (int i = size / 2 - 1; i >= 0;i--) {
		MinHeap(array, size, i);
	}
}

void HeapSort(int array[], int size) {
	RepeatMinHeap(array, size);

	for (int i = size - 1; i >= 0; i--) {
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		MinHeap(array, i, 0);
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

// Main function
int main() {
	int data[6] = { 6, 5, 12, 10, 9, 1 };
	int size = sizeof(data) / sizeof(data[0]);

	printf("Unsorted array:\n");
	printArray(data, size);

	HeapSort(data, size);

	printf("Sorted array (descending order):\n");
	printArray(data, size);

	return 0;
}
