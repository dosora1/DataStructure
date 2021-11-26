//������ ���� ����

#include <iostream>

using namespace std;

int m, n;
int arr1[101][101];	//��� �Ѵ°� ���� 
int arr2[101][101];	//��� ���°� ����
int dy[4] = { 0, 0, 1, -1 };  //�� ���� Ž��
int dx[4] = { 1, -1, 0, 0 };

//������ �Ѵ� �Լ�
void recur1(int row, int col) {
	if (row == -1 || col == -1 || row == m || col == n) return; //����̸� ����

	if (arr1[row][col] == 1) return; //���� ������ ����

	arr1[row][col] = 1; //���� ������ �� on
	for (int i = 0; i < 4; i++) recur1(row + dy[i], col + dx[i]); //�ֺ��� Ž��, ���

}

//������ ���� �Լ�
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
			if (arr1[i][j] == 0) { recur1(i, j); cnt1++; }	//���������ִٸ� �ѱ�
			if (arr2[i][j] == 1) { recur2(i, j); cnt2++; }	//���������ִٸ� ����
		}
	}

	cout << cnt1<<' '<<cnt2;

	return 0;
}