#include <iostream> 
#include <vector>
using namespace std;

vector<int> a[101]; //인접리스트
bool check[101]; //인접한 값이 존재하는가
int cnt = 0;

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!check[y]) {
			dfs(y);
			cnt++;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	} // 입력 들어올 때마다 업데이트 됨
	dfs(1);
	cout << cnt;
}
