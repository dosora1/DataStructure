#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	
	//c++���� �Ҽ��� ǥ���ϱ�
	cout << fixed;
	cout.precision(4);
	cout << -b / a;
	return 0;
}