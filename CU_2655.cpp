#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	
	//c++에서 소수점 표현하기
	cout << fixed;
	cout.precision(4);
	cout << -b / a;
	return 0;
}