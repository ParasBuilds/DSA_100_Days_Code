#include <stdio.h>

typedef struct {
	int position;
	int speed;
} Car;

static void swap_cars(Car *a, Car *b) {
	Car temp = *a;
	*a = *b;
	*b = temp;
}

static void sort_cars_desc(Car *cars, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (cars[j].position < cars[j + 1].position) {
				swap_cars(&cars[j], &cars[j + 1]);
			}
		}
	}
}

int main(void) {
	int target;
	int n;
	if (scanf("%d %d", &target, &n) != 2) {
		return 0;
	}
	if (n <= 0) {
		printf("0\n");
		return 0;
	}

	Car *cars = (Car *)malloc(sizeof(Car) * n);
	if (!cars) {
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (scanf("%d", &cars[i].position) != 1) {
			free(cars);
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &cars[i].speed) != 1) {
			free(cars);
			return 0;
		}
	}

	sort_cars_desc(cars, n);

	int fleets = 0;
	double slowest_time = -1.0;
	for (int i = 0; i < n; i++) {
		double time = (double)(target - cars[i].position) / (double)cars[i].speed;
		if (time > slowest_time) {
			fleets++;
			slowest_time = time;
		}
	}

	printf("%d\n", fleets);

	free(cars);
	return 0;
}
