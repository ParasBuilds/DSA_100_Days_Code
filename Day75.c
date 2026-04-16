#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
	long long *arr = NULL;
	int n = 0, cap = 0;
	long long x;

	while (scanf("%lld", &x) == 1) {
		if (n == cap) {
			cap = cap ? cap * 2 : 16;
			long long *tmp = realloc(arr, cap * sizeof *arr);
			if (!tmp) return 1;
			arr = tmp;
		}
		arr[n++] = x;
	}

	if (n == 0) {
		printf("0\n");
		free(arr);
		return 0;
	}

	int maxlen = 0;
	long long sum = 0;

	int size = 1;
	while (size < n * 2) size <<= 1;

	long long *keys = malloc(size * sizeof *keys);
	int *vals = malloc(size * sizeof *vals);
	unsigned char *used = malloc(size * sizeof *used);
	if (!keys || !vals || !used) return 1;
	for (int i = 0; i < size; ++i) used[i] = 0;

	for (int i = 0; i < n; ++i) {
		sum += arr[i];
		if (sum == 0) {
			if (i + 1 > maxlen) maxlen = i + 1;
		}

		uint64_t h = (uint64_t)sum * 11400714819323198485ULL;
		int idx = (int)(h & (uint64_t)(size - 1));
		int found = -1;
		while (used[idx]) {
			if (keys[idx] == sum) { found = vals[idx]; break; }
			idx = (idx + 1) & (size - 1);
		}

		if (found != -1) {
			int len = i - found;
			if (len > maxlen) maxlen = len;
		} else {
			used[idx] = 1;
			keys[idx] = sum;
			vals[idx] = i;
		}
	}

	printf("%d\n", maxlen);

	free(arr);
	free(keys);
	free(vals);
	free(used);
	return 0;
}

