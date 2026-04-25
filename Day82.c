#include <stdio.h>
#include <stdlib.h>

static int lower_bound(const int *arr, int n, int x) {
	int left = 0;
	int right = n;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] < x) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	return left;
}

static int upper_bound(const int *arr, int n, int x) {
	int left = 0;
	int right = n;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] <= x) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	return left;
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

	int x;
	if (scanf("%d", &x) != 1) {
		free(arr);
		return 0;
	}

	int lb = lower_bound(arr, n, x);
	int ub = upper_bound(arr, n, x);

	printf("%d %d\n", lb, ub);
	free(arr);
	return 0;
}
