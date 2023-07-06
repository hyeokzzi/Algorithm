#include<iostream>
using namespace std;
int N;
int dx[3] = { -1, 0, 1 };
int dy[3] = { -1, -1 , -1 };
int arr[16][16] = { 0, };
int cnt = 0;
void dfs (int layer) {

	for (int i = 0; i < N; i++) {
		// arr[layer][i] 위치가 가능한지 확인
		// 1. 좌측 위 대각선
		int flag = 0;
		for (int k = 0; k < 3; k++) {
			int x = i;
			int y = layer;
			while (1) {
				x = x + dx[k];
				y = y + dy[k];
				if (x < 0 || y < 0 || x >= N || y >= N) break;
				if (arr[y][x] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) continue;
		if (layer == N - 1) cnt++;
		arr[layer][i] = 1;
		dfs(layer + 1);
		arr[layer][i] = 0;
	}
}


int main() {
	cin >> N;
	// 대각선, 가로, 세로 불가능
	dfs(0);
	cout << cnt;
	return 0;
}