/*
 *
 * 04 Bubble Sort
 * Name : Arun R
 * Roll No.: 12
 */
#include <stdio.h>
int bubbleSort(int array[], int size) {
	int i, j, temp;
	for (i=size; i>=0; i--) {
		for (j=0; j<i; j++) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
int main() {
	int i, j, array[100], size, temp;

	printf("Enter number of elements in the array : ");
	scanf("%d", &size);

	printf("Enter the array\n");
	for (i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}

	bubbleSort(array, size);

	printf("Sorted array \n");
	for (i=0; i<size; i++) {
		printf("%d\n", array[i]);
	}
}
