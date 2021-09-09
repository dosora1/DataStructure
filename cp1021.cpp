#include <iostream>
#include <algorithm> //rotate
#include <vector>
using namespace std;

int main() {
    int N, M, num, cnt = 0;
    vector<int> deque;

    cin >> N >> M;
    //숫자리스트 만들기
    for (int i = 1; i <= N; i++)
        deque.push_back(i);

    //찾으려고 하는 수
    for (int j = 0; j < M; j++) {
        cin >> num;
        for (int i = 0; i < N; i++) {
            if (deque[i] == num) {
                //앞 뒤 탐색 중 빠른 것을 cnt에 더해줌.
                cnt += min(i, N - i);
                rotate(deque.begin(), deque.begin() + i + 1, deque.end() - j); //(i+1)만큼 왼쪽으로 이동
                break;
            }
        }
        N--;
    }
    cout << cnt;
    return 0;
}