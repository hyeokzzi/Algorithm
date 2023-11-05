#include<iostream>
#include<queue>
using namespace std;
int n, m, k;
int arr[101][101];
int max_cnt;
int dx[4] = { 0, 1, 0 ,-1 };
int dy[4] = { -1, 0, 1, 0 };

bool visited[101][101];
void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> y >> x;
		arr[y][x] = 1;
	}
}

int func(int y, int x) {
	int cnt = 0;
	queue<pair<int, int>> que;
	que.push({ y,x });
	while (!que.empty()) {
		int size = que.size();
		cnt += size;
		while (size--) {
			int ax = que.front().second;
			int ay = que.front().first;
			que.pop();

			for (int i = 0; i < 4; i++) {
				int tx = ax + dx[i];
				int ty = ay + dy[i];
				if (tx < 1 || tx > m || ty < 1 || ty > n) continue;
				if (visited[ty][tx] || arr[ty][tx] != 1) continue;
				visited[ty][tx] = true;
				que.push({ ty,tx });
			}
		}
	}
	return cnt;
}


void solution() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				visited[i][j] = true;
				max_cnt = max(func(i, j), max_cnt);
			}
		}
	}
	cout << max_cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}