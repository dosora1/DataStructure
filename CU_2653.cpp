/*
��Ʈ��ŷ
*/

#include <iostream>
using namespace std;

int n, cnt = 0;

void fun(int n, int bit) {
	if (!n) { // n�� 0�̸�
		cnt++;
		return;
	}
	fun(n - 1, 1); // n�� 0�� �ƴϸ�, �����ڸ� 1�� ȣ��
	if (bit) fun(n - 1, 0); // bit�� 1�̶�� ���� �ڸ� �ѹ� �� ����, ����, ���
}

int main() {
	cin>>n;
	fun(n, 1);
	cout<<cnt;
	return 0;
}