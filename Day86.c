#include <stdio.h>

int main(void) {
	long long n;
	if (scanf("%lld", &n) != 1 || n < 0) {
		return 0;
	}

	long long left = 0;
	long long right = n;
	long long ans = 0;

	while (left <= right) {
		long long mid = left + (right - left) / 2;
		long long sq = mid * mid;
		if (sq == n) {
			ans = mid;
			break;
		}
		if (sq < n) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	printf("%lld\n", ans);
	return 0;
}
