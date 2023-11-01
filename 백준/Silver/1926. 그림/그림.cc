#include<iostream>
using namespace std;
int n, m, arr[501][501];
int max_sum = 0;
int pCnt = 0;
int cnt = 0;
int dx[4] = { 0, 1, 0 , -1 };
int dy[4] = { -1, 0 ,1 , 0 };
bool visited[501][501] = { false };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int y, int x) {
	visited[y][x] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
		if (visited[ty][tx] || arr[ty][tx] == 0) continue;
		dfs(ty, tx);
	}
}


void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				pCnt++;
				dfs(i, j);
				max_sum = max(max_sum, cnt);
			}
		}
	}
	cout << pCnt << '\n';
	cout << max_sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	return 0;
}