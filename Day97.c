#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
} Interval;

typedef struct {
	int *data;
	int size;
	int capacity;
} MinHeap;

static int compare_intervals(const void *a, const void *b) {
	const Interval *ia = (const Interval *)a;
	const Interval *ib = (const Interval *)b;
	if (ia->start != ib->start) {
		return ia->start - ib->start;
	}
	return ia->end - ib->end;
}

static void heap_init(MinHeap *heap, int capacity) {
	heap->data = (int *)malloc(sizeof(int) * capacity);
	heap->size = 0;
	heap->capacity = capacity;
}

static void heap_free(MinHeap *heap) {
	free(heap->data);
	heap->data = NULL;
	heap->size = 0;
	heap->capacity = 0;
}

static void heap_swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

static void heap_push(MinHeap *heap, int value) {
	int idx = heap->size;
	heap->data[idx] = value;
	heap->size++;

	while (idx > 0) {
		int parent = (idx - 1) / 2;
		if (heap->data[parent] <= heap->data[idx]) {
			break;
		}
		heap_swap(&heap->data[parent], &heap->data[idx]);
		idx = parent;
	}
}

static int heap_peek(const MinHeap *heap) {
	return heap->data[0];
}

static void heap_pop(MinHeap *heap) {
	if (heap->size == 0) {
		return;
	}
	heap->data[0] = heap->data[heap->size - 1];
	heap->size--;

	int idx = 0;
	while (1) {
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		int smallest = idx;

		if (left < heap->size && heap->data[left] < heap->data[smallest]) {
			smallest = left;
		}
		if (right < heap->size && heap->data[right] < heap->data[smallest]) {
			smallest = right;
		}
		if (smallest == idx) {
			break;
		}
		heap_swap(&heap->data[idx], &heap->data[smallest]);
		idx = smallest;
	}
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) {
		return 0;
	}
	if (n <= 0) {
		printf("0\n");
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

	MinHeap heap;
	heap_init(&heap, n);

	int max_rooms = 0;
	for (int i = 0; i < n; i++) {
		while (heap.size > 0 && heap_peek(&heap) <= intervals[i].start) {
			heap_pop(&heap);
		}
		heap_push(&heap, intervals[i].end);
		if (heap.size > max_rooms) {
			max_rooms = heap.size;
		}
	}

	printf("%d\n", max_rooms);

	heap_free(&heap);
	free(intervals);
	return 0;
}
