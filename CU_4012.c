// ���� ���
// �Է� ���� ��� ���� �߰�

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
			rank[i] = ++cnt; //cnt�� �����
			cnt = cnt + val - 1; //�ߺ��� ���
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d %d\n", a[i], rank[a[i]]);

	return 0;
}