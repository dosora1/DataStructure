#include <stdio.h>

int main() {
	double n, m, k;

	scanf("%lf %lf %lf", &n, &m, &k);

	if (n / 100 * k <= m) {
		printf("%s", "YES");
	}
	else {
		printf("%s", "NO");
	}

	return 0;
}