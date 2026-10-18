#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#define MAX_NAME_LENGTH 50;

typedef struct Mountain {
	char name[50]
	int height;
} Mountain;

void printMountain(const Mountain* m) {
	printf("Mountain Name: %s\n", m.name);
	printf("Height: %d meters\n", m.height);
}

bool inputMountain(Mountain* m) {
	printf("Enter mountain name: ");
	if (scanf("%49s", m->name) != 1) {
		return false;
	}
	printf("Enter mountain height (in meters): ");
	if (scanf("%d", &m->height) != 1) {
		return false;
	}
	return true;
}

Mountain highestMountain(const Mountain mountains[], int count) {
	if (count <= 0) {
		Mountain empty = { "", 0 };
		return empty;
	}
	Mountain highest = mountains[0];
	for (int i = 1; i < count; ++i) {
		if (mountains[i].height > highest.height) {
			highest = mountains[i];
		}
	}
	return highest;
}

void printMountainByName(const Mountain mountains[], int count, const char* name) {
	for (int i = 0; i < count; ++i) {
		if (strcmp(mountains[i].name, name) == 0) {
			printMountain(&mountains[i]);
			return;
		}
	}
	printf("Mountain with name '%s' not found.\n", name);
}

int main() {
	Mountain mountains[] = {
		{ "Everest", 8848 },
		{ "K2", 8611 },
		{ "Kangchenjunga", 8586 }
	};
	int count = sizeof(mountains) / sizeof(mountains[0]);

	Mountain highest = highestMountain(mountains, count);
	printf("Highest mountain:\n");
	printMountain(highest);

	printMountainByName(mountains, count, "Everest");
	printMountainByName(mountains, count, "Mount Fuji");

	int n;
	printf("Enter the number of mountains to input: ");
	if (scanf("%d", &n) != 1 || n <= 0)) {
		printf("Invalid number of mountains.\n");
		return 1;
	}

	Mountain* m = (Mountain*)malloc(n * sizeof(Mountain));
	if (m == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	for (int i = 0; i < n; ++i) {
		if (!inputMountain(&m[i])) {
			printf("Invalid input for mountain %d.\n", i + 1);
			free(m);
			return 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		printMountain(&m[i]);
	}

	char name[MAX_NAME_LENGTH];
	printf("Enter the name of the mountain to search: ");
	if (scanf("%49s", name) == 1) {
		printMountainByName(mountains, const, name);


	}

	free(m);
	return 0;
}
