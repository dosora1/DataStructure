#include <iostream>
using namespace std;

int main() {
	int n;
	int A[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> *(A + i);
	}

	for (int j = n-1; j >=0; j--) {
		cout << *(A + j)<<' ';
	}
}