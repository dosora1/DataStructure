// 석차 계산
// 입력 순서 기억 변수 추가

#include <stdio.h>

int rank[200], a[200], n, cnt, val;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		rank[a[i]]--;
	}

	for (int i = 100; i >= 0; i--) {
		if (rank[i] < 0)
		{
			val = rank[i] * (-1);
			rank[i] = ++cnt; //cnt가 등수임
			cnt = cnt + val - 1; //중복을 고려
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d %d\n", a[i], rank[a[i]]);

	return 0;
}