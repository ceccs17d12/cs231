/*
 * 10
 * Binary Search
 * Author : Nikhil M Tomy
 * 
 */

#include <stdio.h>

int selectionSort(int array[], int size) {
	int i, j, pos, temp;
	for (i=0; i<size; i++) {
		pos = i;

		for (j=i; j<size; j++) {
			if (array[j] < array[pos]) {
				pos =j;
			}
		}
		if (i != pos) {
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
		}
	}
}

int main() {
	int i, beg, mid, last, found=0, array[100], element, size;

	printf("Enter number of elements : ");
	scanf("%d", &size);

	printf("Enter elements\n");
	for (i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}

	selectionSort(array, size);

	printf("Sorted array\n");
	for (i=0; i<size; i++) {
		printf("%d\n", array[i]);
	}
	printf("Enter element to search : ");
	scanf("%d", &element);

	beg = 0;
	last = size-1;
	while (last >= beg) {
		mid = (beg + last)/2;
		if (array[mid] == element) {
			found = 1;
			break;
		} else if (array[mid] > element) {
			last = mid - 1;
		} else {
			beg = mid + 1;
		}
	}

	if (found) {
		printf("Element found at position %d\n", mid+1);
	} else {
		printf("Element not found\n");
	}
}