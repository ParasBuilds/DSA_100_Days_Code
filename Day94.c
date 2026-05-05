#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n = 0;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	int *arr = (int *)malloc((size_t)n * sizeof(int));
	if (!arr) {
		return 1;
	}

	int max_val = 0;
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &arr[i]) != 1) {
			free(arr);
			return 0;
		}
		if (arr[i] > max_val) {
			max_val = arr[i];
		}
	}

	int *freq = (int *)calloc((size_t)max_val + 1u, sizeof(int));
	int *out = (int *)malloc((size_t)n * sizeof(int));
	if (!freq || !out) {
		free(arr);
		free(freq);
		free(out);
		return 1;
	}

	for (int i = 0; i < n; ++i) {
		freq[arr[i]]++;
	}

	for (int i = 1; i <= max_val; ++i) {
		freq[i] += freq[i - 1];
	}

	// Stable placement: iterate from right to left.
	for (int i = n - 1; i >= 0; --i) {
		int v = arr[i];
		out[--freq[v]] = v;
	}

	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", out[i]);
	}
	printf("\n");

	free(arr);
	free(freq);
	free(out);
	return 0;
}
