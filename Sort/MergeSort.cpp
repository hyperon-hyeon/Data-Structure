#include <stdio.h>

void Merge(int array[], int left, int mid, int right) {
	int n1 = mid -left+ 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = array[left+i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = array[mid +1+ i];
	}

	int i = 0, j = 0, k=left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			array[k++] = L[i++];
		else 
			array[k++] = R[j++];
	}

	while (i < n1) {
		array[k++] = L[i++];
	}
	while (j < n2) {
		array[k++] = R[j++];
	}
}

void MergeSort(int array[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		MergeSort(array, left, mid);
		MergeSort(array, mid+1, right);

		Merge(array, left, mid, right);

	}
}

int main() {
	int data[6] = { 6, 5, 12, 10, 9, 1 };
	int size = sizeof(data) / sizeof(data[0]);

	printf("Unsorted array:\n");
	for (int i = 0; i < size; i++)
		printf("%d ", data[i]);
	printf("\n");

	MergeSort(data, 0, size - 1);

	printf("Sorted array:\n");
	for (int i = 0; i < size; i++)
		printf("%d ", data[i]);
	printf("\n");
	return 0;
}