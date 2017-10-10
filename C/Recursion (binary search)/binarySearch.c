#include <stdio.h>

int RecursiveBinarySearch(int data[], int low, int high, int key);

int main() {
	int key, index;

	printf("Binary Search : \n");
	printf("\n");

	int data[] = { 1, 2, 4, 5, 7, 9, 12, 15, 16, 17, 20, 24, 27, 28, 36, 38, 44, 45, 48, 50, 51, 52, 54, 56, 60, 64, 72, 75, 77, 79, 80, 81, 89, 94, 98, 100, 104, 116, 124, 156, 157, 164, 182, 200 };

	printf("Element to be searched = ");
	scanf("%d",&key);
	printf("\n");

	index = RecursiveBinarySearch(data, 0, sizeof(data) / sizeof(*data), key);

	if (index == -1) {
		printf("Key not found! \n");
	}
	else {
		printf("Key found at index : %d \n", index);
	}
	printf("\n");

	return 0;
}

int RecursiveBinarySearch(int data[], int low, int high, int key) {
	int mid;
	if (low <= high) {
		mid = (low + high) / 2;
		if (data[mid] == key) {
			return mid;
		}
		else if (data[mid] > key) {
			return RecursiveBinarySearch(data, low, (mid - 1), key);
		}
		else {
			return RecursiveBinarySearch(data, (mid + 1), high, key);
		}
	}
	return -1;
}