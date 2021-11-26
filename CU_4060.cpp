//전광판 전구 조작

#include <iostream>

using namespace std;

int m, n;
int arr1[101][101];	//모두 켜는거 계산용 
int arr2[101][101];	//모두 끄는거 계산용
int dy[4] = { 0, 0, 1, -1 };  //네 방향 탐색
int dx[4] = { 1, -1, 0, 0 };

//전구를 켜는 함수
void recur1(int row, int col) {
	if (row == -1 || col == -1 || row == m || col == n) return; //경계이면 종료

	if (arr1[row][col] == 1) return; //켜져 있으면 종료

	arr1[row][col] = 1; //꺼져 있으면 불 on
	for (int i = 0; i < 4; i++) recur1(row + dy[i], col + dx[i]); //주변을 탐색, 재귀

}

//전구를 끄는 함수
void recur2(int row, int col) {
	if (row == -1 || col == -1 || row == m || col == n) return;

	if (arr2[row][col] == 0) return;

	arr2[row][col] = 0;
	for (int i = 0; i < 4; i++) recur2(row + dy[i], col + dx[i]);

}

int main() {

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr1[i][j];
			arr2[i][j] = arr1[i][j];
		}
	}

	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i][j] == 0) { recur1(i, j); cnt1++; }	//전구꺼져있다면 켜기
			if (arr2[i][j] == 1) { recur2(i, j); cnt2++; }	//전구켜져있다면 끄기
		}
	}

	cout << cnt1<<' '<<cnt2;

	return 0;
}