#include <stdio.h>

void InsertionSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int key = array[i];
		int j = i - 1;

		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j--;
		}
		array[j+ 1] = key;
	}
}

int main() {
	int data[5] = { 9,5,1,4,3 };
	int size = sizeof(data) / sizeof(data[0]);

	printf("[Unsorted Data] ");
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}

	InsertionSort(data, size);

	printf("\n[Sorted Data] ");
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	
	return 0;

}