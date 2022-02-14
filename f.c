#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,n; //지하철,셔틀
	int cnt = 0, p=0;

	//scan
	int** arr1;
	int** arr2;
	//N
	scanf("%d", &N);

	arr1 = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr1[i] = (int*)malloc(sizeof(int) * 4);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	//n
	scanf("%d", &n);

	arr2 = (int)malloc(sizeof(int) * n);
	for (int i = 0; i < N; i++) {
		arr2[i] = (int*)malloc(sizeof(int) * 4);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}

	//시간 비교
	int ind = 0;
	for (int i = 0; i < n; i++) {
		if (ind == n) break;
		if (arr1[ind][0] <= arr2[i][0] && arr1[ind][1] <= arr2[i][1] && arr1[ind][2] <= arr2[i][2]) { 
			cnt += arr1[i][3];
			ind++;	
		}
		cnt -= arr2[i][3];
		p += cnt;
	}

	printf("%d\n", p);

	free(arr1);
	free(arr1[0]);
	free(arr2);
	free(arr2[0]);

	return 0;
}