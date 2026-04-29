#include <stdio.h>
#include <stdlib.h>

static int compare_ints(const void *a, const void *b) {
	int x = *(const int *)a;
	int y = *(const int *)b;
	return (x > y) - (x < y);
}

static int can_place(const int *pos, int n, int k, int min_dist) {
	int count = 1;
	int last = pos[0];

	for (int i = 1; i < n; i++) {
		if (pos[i] - last >= min_dist) {
			count++;
			last = pos[i];
			if (count >= k) {
				return 1;
			}
		}
	}

	return 0;
}

int main(void) {
	int n, k;

	if (scanf("%d %d", &n, &k) != 2) {
		return 0;
	}

	if (n <= 0 || k <= 0) {
		return 0;
	}

	int *pos = (int *)malloc((size_t)n * sizeof(int));
	if (!pos) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (scanf("%d", &pos[i]) != 1) {
			free(pos);
			return 0;
		}
	}

	qsort(pos, (size_t)n, sizeof(int), compare_ints);

	int low = 0;
	int high = pos[n - 1] - pos[0];
	int best = 0;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (can_place(pos, n, k, mid)) {
			best = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	printf("%d", best);
	free(pos);
	return 0;
}
