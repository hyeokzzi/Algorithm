#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
int arr[301][301];
int visited[301][301];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };


void dfs(int y, int x) {
	visited[y][x] = 1;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (visited[ty][tx] == 0 && arr[ty][tx] <= 0) cnt++;
		if (tx < 1 || tx > M || ty < 1 || ty > N)continue;
		if (visited[ty][tx] || arr[ty][tx] <= 0) continue;
		dfs(ty, tx);
	}
	arr[y][x] -= cnt;
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int year = 0;
	while (1) {
		int area = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visited[i][j] && arr[i][j] > 0) {
					dfs(i, j);
					area++;
				}
			}
		}
		if (area >= 2) {
			cout << year;
			return 0;
		}
		else if (area == 0) {
			cout << area;
			return 0;
		}
		year++;
	}



	return 0;
}