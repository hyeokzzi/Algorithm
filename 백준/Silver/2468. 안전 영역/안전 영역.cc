#include<iostream>
using namespace std;
int N, max_cnt = 1;
int arr[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int y, int x, bool (*visit)[101], int height) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 1 || tx > N || ty < 1 || ty > N) continue;
		if (visit[ty][tx] == true || arr[ty][tx] <= height) continue;
		dfs(ty, tx, visit, height);
	}
}


int main() {
	cin >> N;
	int max_h = 0;
	int min_h = 100;
 	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			max_h = max(arr[i][j], max_h);
			min_h = min(arr[i][j], min_h);
		}
	}

	for (int i = max_h; i >= min_h; i--) {
		bool visited[101][101] = { false };
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][k] > i && visited[j][k] == false) {
					dfs(j, k, visited, i);
					cnt++;
				}
			}
		}
		max_cnt = max(max_cnt, cnt);
	}
	cout << max_cnt;
	return 0;
}