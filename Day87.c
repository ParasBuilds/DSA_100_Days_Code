#include <stdio.h>
#include <stdlib.h>

static int compare_ints(const void *a, const void *b) {
	int left = *(const int *)a;
	int right = *(const int *)b;
	return (left > right) - (left < right);
}

static int binary_search_iterative(const int *arr, int n, int target) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	int *arr = (int *)malloc((size_t)n * sizeof(int));
	if (!arr) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			free(arr);
			return 0;
		}
	}

	int target;
	int has_target = (scanf("%d", &target) == 1);

	qsort(arr, (size_t)n, sizeof(int), compare_ints);

	if (has_target) {
		int index = binary_search_iterative(arr, n, target);
		printf("%d\n", index);
	} else {
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d", arr[i]);
		}
		printf("\n");
	}

	free(arr);
	return 0;
}
