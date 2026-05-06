#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double *data;
	int size;
	int cap;
} Bucket;

static int compare_doubles(const void *a, const void *b) {
	double da = *(const double *)a;
	double db = *(const double *)b;
	if (da < db) {
		return -1;
	}
	if (da > db) {
		return 1;
	}
	return 0;
}

static void bucket_init(Bucket *b) {
	b->data = NULL;
	b->size = 0;
	b->cap = 0;
}

static void bucket_push(Bucket *b, double value) {
	if (b->size == b->cap) {
		int new_cap = (b->cap == 0) ? 4 : b->cap * 2;
		double *new_data = (double *)realloc(b->data, new_cap * sizeof(double));
		if (!new_data) {
			fprintf(stderr, "Memory allocation failed.\n");
			exit(1);
		}
		b->data = new_data;
		b->cap = new_cap;
	}
	b->data[b->size++] = value;
}

static void bucket_free(Bucket *b) {
	free(b->data);
	b->data = NULL;
	b->size = 0;
	b->cap = 0;
}

int main(void) {
	int n = 0;

	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	double *arr = (double *)malloc(n * sizeof(double));
	if (!arr) {
		fprintf(stderr, "Memory allocation failed.\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (scanf("%lf", &arr[i]) != 1) {
			free(arr);
			return 0;
		}
	}

	Bucket *buckets = (Bucket *)malloc(n * sizeof(Bucket));
	if (!buckets) {
		fprintf(stderr, "Memory allocation failed.\n");
		free(arr);
		return 1;
	}

	for (int i = 0; i < n; i++) {
		bucket_init(&buckets[i]);
	}

	for (int i = 0; i < n; i++) {
		int idx = (int)(arr[i] * n);
		if (idx < 0) {
			idx = 0;
		} else if (idx >= n) {
			idx = n - 1;
		}
		bucket_push(&buckets[idx], arr[i]);
	}

	int out = 0;
	for (int i = 0; i < n; i++) {
		if (buckets[i].size > 1) {
			qsort(buckets[i].data, buckets[i].size, sizeof(double), compare_doubles);
		}
		for (int j = 0; j < buckets[i].size; j++) {
			arr[out++] = buckets[i].data[j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%.6f", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		bucket_free(&buckets[i]);
	}
	free(buckets);
	free(arr);
	return 0;
}
