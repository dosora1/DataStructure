//���� ��ȹ�� : ���� ������ ū ������ Ǭ��.

#include <iostream>
using namespace std;

int cnt = 0;

void f(int n,int m){
	if (n == 1) {
		cnt++;
		return;
	}
	if (n < m) m = n;
	
	for (int i = 1; i < n; i++) {
		f(n - i, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	f(n, m);
	
	cout << cnt<<endl;

	return 0;
}