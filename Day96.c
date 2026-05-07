#include <stdio.h>
#include <stdlib.h>

static long long merge_sort(int *arr, int left, int right, int *temp) {
    if (left >= right) {
        return 0LL;
    }
    int mid = left + (right - left) / 2;
    long long inv_count = 0;
    inv_count += merge_sort(arr, left, mid, temp);
    inv_count += merge_sort(arr, mid + 1, right, temp);

    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (long long)(mid - i + 1);
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
    return inv_count;
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
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            free(temp);
            return 0;
        }
    }
    long long inversions = merge_sort(arr, 0, n - 1, temp);
    printf("%lld\n", inversions);
    free(arr);
    free(temp);
    return 0;
}
