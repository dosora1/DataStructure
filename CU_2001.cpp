// 최소 대금

#include <iostream>
using namespace std;

int main() {
	double pasta_min = 2001, juice_min = 2001;
	double arr[5];

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];

		if (i < 3) {
			if (arr[i] <pasta_min) pasta_min = arr[i];
		}
		else {
			if (arr[i] < juice_min) juice_min = arr[i];
		}
	}

	printf("%.1lf\n", (pasta_min + juice_min) * 1.1);

	return 0;
}