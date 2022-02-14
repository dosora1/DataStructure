#include <stdio.h>

int main() {
	int arr[3];
	int min = 241;
	int r = 0;

	for (int i = 0; i < 3; i++) {
		scanf("%d", arr + i);
		if (arr[i] < min) {
			min = arr[i];
			r = i;
		}
	}

	printf("%s ", "GO");
	switch (r) {
	case 0: 
		printf("%s\n", "SANG");
		break;
	case 1: 
		printf("%s\n", "HAN");
		break;

	case 2:
		printf("%s\n", "JUNG");
		break;
	}

	return 0;
}