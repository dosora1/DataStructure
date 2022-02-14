#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int height = n, width = 20;

	//할당
	char** arr;
	arr = (char**)malloc(sizeof(char*) * height);
	arr[0] = (char*)malloc(sizeof(char) * width * height);
	for (int i = 1; i < height; i++) {
		arr[i] =(char*)malloc(sizeof(char)*width);
	}

	char* arr2;
	arr2 = (char*)malloc(sizeof(char) * n);

	//scan
	for (int i = 0; i < n; i++) {
		scanf("%s", &arr[i]);
		//마지막 탐색
		for (int j = 0; j < n; j ++) {
			arr2[j] = arr[i][strlen(arr[i]) - 1];
		}
	}

	//test
	for (int i = 0; i < n; i++) {
		printf("%c ", arr2[i - 1]);
	}

	free(arr[0]);
	free(arr);
	free(arr2);
	return 0;
}