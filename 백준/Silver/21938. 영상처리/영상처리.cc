#include<iostream>
using namespace std;
int arr[1001][1001];
bool visited[1001][1001] = { false };
int N, M;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1 ,0 , 1, 0 };

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx <= 0 || tx > M || ty <= 0 || ty > N) continue;
		if (visited[ty][tx] == true || arr[ty][tx] != 255) continue;
		dfs(ty, tx);
	}
}
int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 3; k++) {
				int value;
				cin >> value;
				arr[i][j] += value;
			}
			arr[i][j] /= 3;
		}
	}
	int T;
	cin >> T;
	// 배열 처리
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] >= T) {
				arr[i][j] = 255;
			}
			else { 
				arr[i][j] = 0; 
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 255 && visited[i][j] == false) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;

	return 0;
}