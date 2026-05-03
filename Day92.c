#include <stdio.h>
#include <stdlib.h>

static void swap_int(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static int partition_lomuto(int *arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; ++j) {
		if (arr[j] <= pivot) {
			++i;
			swap_int(&arr[i], &arr[j]);
		}
	}

	swap_int(&arr[i + 1], &arr[high]);
	return i + 1;
}

static void quick_sort(int *arr, int low, int high) {
	if (low >= high) {
		return;
	}

	int p = partition_lomuto(arr, low, high);
	quick_sort(arr, low, p - 1);
	quick_sort(arr, p + 1, high);
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

	quick_sort(arr, 0, n - 1);

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
