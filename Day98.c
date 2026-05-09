#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
} Interval;

static int compare_intervals(const void *a, const void *b) {
	const Interval *ia = (const Interval *)a;
	const Interval *ib = (const Interval *)b;
	if (ia->start != ib->start) {
		return ia->start - ib->start;
	}
	return ia->end - ib->end;
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) {
		return 0;
	}
	if (n <= 0) {
		return 0;
	}

	Interval *intervals = (Interval *)malloc(sizeof(Interval) * n);
	if (!intervals) {
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (scanf("%d %d", &intervals[i].start, &intervals[i].end) != 2) {
			free(intervals);
			return 0;
		}
	}

	qsort(intervals, n, sizeof(Interval), compare_intervals);

	Interval current = intervals[0];
	for (int i = 1; i < n; i++) {
		if (intervals[i].start <= current.end) {
			if (intervals[i].end > current.end) {
				current.end = intervals[i].end;
			}
		} else {
			printf("%d %d\n", current.start, current.end);
			current = intervals[i];
		}
	}
	printf("%d %d\n", current.start, current.end);

	free(intervals);
	return 0;
}
