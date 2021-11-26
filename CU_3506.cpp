// 블럭 채우기1
// 백트래킹, 탐색 기반 설계

#include <iostream>
using namespace std;

int answer = 0;

void fillGrid(int idx, int len) {
    // 기저사례: 범위를 넘었다면 종료
    if (idx > len) return;

    // 기저사례: 끝까지 채웠다면 종료
    if (idx == len) {
        answer++;
        return;
    }

    // 세로로 둔다.
    fillGrid(idx + 1, len);
    // 가로로 둔다.
    fillGrid(idx + 2, len);
}

int main() {
    int len;
    cin >> len;
    fillGrid(0, len);

    cout << answer << endl;
    return 0;
}