#include <stdio.h>
#include <stdlib.h>

static void merge(int *arr, int left, int mid, int right, int *temp) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (int idx = left; idx <= right; idx++) {
		arr[idx] = temp[idx];
	}
}

static void merge_sort(int *arr, int left, int right, int *temp) {
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;
	merge_sort(arr, left, mid, temp);
	merge_sort(arr, mid + 1, right, temp);
	merge(arr, left, mid, right, temp);
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	int *arr = (int *)malloc((size_t)n * sizeof(int));
	int *temp = (int *)malloc((size_t)n * sizeof(int));
	if (!arr || !temp) {
		free(arr);
		free(temp);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			free(arr);
			free(temp);
			return 0;
		}
	}

	merge_sort(arr, 0, n - 1, temp);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");

	free(arr);
	free(temp);
	return 0;
}
