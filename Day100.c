#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
	int x = *(const int *)a;
	int y = *(const int *)b;
	return (x > y) - (x < y);
}

static int lower_bound_int(const int *arr, int n, int target) {
	int left = 0;
	int right = n; /* [left, right) */
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

static void bit_update(int *bit, int n, int idx, int delta) {
	while (idx <= n) {
		bit[idx] += delta;
		idx += idx & -idx;
	}
}

static int bit_query(int *bit, int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += bit[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) {
		return 0;
	}

	if (n <= 0) {
		return 0;
	}

	int *arr = (int *)malloc((size_t)n * sizeof(int));
	int *sorted = (int *)malloc((size_t)n * sizeof(int));
	int *counts = (int *)malloc((size_t)n * sizeof(int));
	if (!arr || !sorted || !counts) {
		free(arr);
		free(sorted);
		free(counts);
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &arr[i]) != 1) {
			free(arr);
			free(sorted);
			free(counts);
			return 0;
		}
		sorted[i] = arr[i];
	}

	qsort(sorted, (size_t)n, sizeof(int), cmp_int);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || sorted[i] != sorted[i - 1]) {
			sorted[m++] = sorted[i];
		}
	}

	int *bit = (int *)calloc((size_t)(m + 1), sizeof(int));
	if (!bit) {
		free(arr);
		free(sorted);
		free(counts);
		return 0;
	}

	for (int i = n - 1; i >= 0; --i) {
		int pos = lower_bound_int(sorted, m, arr[i]) + 1; /* 1-based */
		counts[i] = bit_query(bit, pos - 1);
		bit_update(bit, m, pos, 1);
	}

	for (int i = 0; i < n; ++i) {
		if (i) {
			printf(" ");
		}
		printf("%d", counts[i]);
	}
	printf("\n");

	free(arr);
	free(sorted);
	free(counts);
	free(bit);
	return 0;
}
