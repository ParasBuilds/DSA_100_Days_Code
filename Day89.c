#include <stdio.h>

static int can_allocate_with_limit(const long long *pages, int n, int m, long long limit) {
	long long current = 0;
	int students = 1;

	for (int i = 0; i < n; ++i) {
		if (pages[i] > limit) {
			return 0;
		}
		if (current + pages[i] <= limit) {
			current += pages[i];
		} else {
			students++;
			current = pages[i];
			if (students > m) {
				return 0;
			}
		}
	}

	return 1;
}

int main(void) {
	int n = 0, m = 0;
	if (scanf("%d %d", &n, &m) != 2) {
		return 0;
	}
	if (n <= 0 || m <= 0) {
		return 0;
	}

	long long sum = 0;
	long long max_pages = 0;
	long long pages[100000];

	for (int i = 0; i < n; ++i) {
		long long book = 0;
		if (scanf("%lld", &book) != 1) {
			return 0;
		}
		pages[i] = book;
		sum += book;
		if (book > max_pages) {
			max_pages = book;
		}
	}

	long long low = max_pages;
	long long high = sum;
	long long answer = sum;

	while (low <= high) {
		long long mid = low + (high - low) / 2;
		if (can_allocate_with_limit(pages, n, m, mid)) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	printf("%lld", answer);
	return 0;
}
