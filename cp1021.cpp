#include <iostream>
#include <algorithm> //rotate
#include <vector>
using namespace std;

int main() {
    int N, M, num, cnt = 0;
    vector<int> deque;

    cin >> N >> M;
    //���ڸ���Ʈ �����
    for (int i = 1; i <= N; i++)
        deque.push_back(i);

    //ã������ �ϴ� ��
    for (int j = 0; j < M; j++) {
        cin >> num;
        for (int i = 0; i < N; i++) {
            if (deque[i] == num) {
                //�� �� Ž�� �� ���� ���� cnt�� ������.
                cnt += min(i, N - i);
                rotate(deque.begin(), deque.begin() + i + 1, deque.end() - j); //(i+1)��ŭ �������� �̵�
                break;
            }
        }
        N--;
    }
    cout << cnt;
    return 0;
}