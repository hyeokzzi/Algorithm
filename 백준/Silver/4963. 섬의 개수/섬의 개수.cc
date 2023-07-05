#include<iostream>
#include<queue>
using namespace std;
int N, M;
int arr[51][51];
bool visited[51][51] = { false };

int dx[8] = { 0 ,1, 1, 1, 0, -1 , -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx <= 0 || tx > N || ty <= 0 || ty > M) continue;
		if (arr[ty][tx] == 1 && visited[ty][tx] == false) dfs(ty, tx);
	}
}


int main() {
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		// 초기화
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
			}
		}
		int cnt = 0;
		// DFS 수행
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] == 1 && visited[i][j] == false) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		// 출력
		cout << cnt << '\n';
	}
	return 0;
}