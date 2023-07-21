#include<iostream>
#include<vector>
using namespace std;

int N, M;
int arr[501][501] = { 0, };
int visited[501][501] = { 0, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			visited[i][j] = -1;
		}
	}
}

int dfs(int y, int x) {
	if (y == N && x == M) return 1;
	if (visited[y][x] != -1) return visited[y][x];
	visited[y][x] = 0; // 방문표시
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		// 이동 불가능
		if (tx < 1 || tx > M || ty < 1 || ty > N) continue;
		if (arr[ty][tx] >= arr[y][x]) continue;
		else visited[y][x] += dfs(ty, tx);
	}
	return visited[y][x];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	cout << dfs(1, 1);

	return 0;
}