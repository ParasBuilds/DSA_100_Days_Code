#include <stdio.h>
#include <stdlib.h>

static void insertion_sort(int *arr, int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = key;
	}
}

int main(void) {
	int n = 0;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	int *arr = (int *)malloc((size_t)n * sizeof(int));
	if (!arr) {
		return 1;
	}

	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &arr[i]) != 1) {
			free(arr);
			return 0;
		}
	}

	// Stable sort that performs well on nearly sorted arrays.
	insertion_sort(arr, n);

	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");

	free(arr);
	return 0;
}
