// �� ä���1
// ��Ʈ��ŷ, Ž�� ��� ����

#include <iostream>
using namespace std;

int answer = 0;

void fillGrid(int idx, int len) {
    // �������: ������ �Ѿ��ٸ� ����
    if (idx > len) return;

    // �������: ������ ä���ٸ� ����
    if (idx == len) {
        answer++;
        return;
    }

    // ���η� �д�.
    fillGrid(idx + 1, len);
    // ���η� �д�.
    fillGrid(idx + 2, len);
}

int main() {
    int len;
    cin >> len;
    fillGrid(0, len);

    cout << answer << endl;
    return 0;
}