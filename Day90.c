#include <stdio.h>

static int can_paint_with_limit(const long long *boards, int n, int k, long long limit) {
	long long current = 0;
	int painters = 1;

	for (int i = 0; i < n; ++i) {
		if (boards[i] > limit) {
			return 0;
		}
		if (current + boards[i] <= limit) {
			current += boards[i];
		} else {
			painters++;
			current = boards[i];
			if (painters > k) {
				return 0;
			}
		}
	}

	return 1;
}

int main(void) {
	int n = 0, k = 0;
	if (scanf("%d %d", &n, &k) != 2) {
		return 0;
	}
	if (n <= 0 || k <= 0) {
		return 0;
	}

	long long sum = 0;
	long long max_board = 0;
	long long boards[100000];

	for (int i = 0; i < n; ++i) {
		long long len = 0;
		if (scanf("%lld", &len) != 1) {
			return 0;
		}
		boards[i] = len;
		sum += len;
		if (len > max_board) {
			max_board = len;
		}
	}

	long long low = max_board;
	long long high = sum;
	long long answer = sum;

	while (low <= high) {
		long long mid = low + (high - low) / 2;
		if (can_paint_with_limit(boards, n, k, mid)) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	printf("%lld", answer);
	return 0;
}
