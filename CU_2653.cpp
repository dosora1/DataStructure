/*
백트래킹
*/

#include <iostream>
using namespace std;

int n, cnt = 0;

void fun(int n, int bit) {
	if (!n) { // n이 0이면
		cnt++;
		return;
	}
	fun(n - 1, 1); // n이 0이 아니면, 이하자리 1로 호출
	if (bit) fun(n - 1, 0); // bit이 1이라면 이하 자리 한번 더 시행, 반전, 재귀
}

int main() {
	cin>>n;
	fun(n, 1);
	cout<<cnt;
	return 0;
}