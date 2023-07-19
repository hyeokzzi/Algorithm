#include<iostream>
using namespace std;
int r, c, cnt = 0, flag = 0;
int visited[5][5];
int arr[5][5];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
void input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> r >> c;
}

void dfs(int y, int x, int level) {
	if (level > 3) return;
	if (arr[y][x] == 1) cnt++;
	if (cnt >= 2) flag = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		// 제외 조건
		if (tx < 0 || tx > 4 || ty < 0 || ty > 4) continue;
		if (arr[ty][tx] == -1) continue;

		int tmp = arr[y][x];
		arr[y][x] = -1;
		dfs(ty, tx, level + 1);
		arr[y][x] = tmp;
	}
	if (arr[y][x] == 1) cnt--;
}

int main() {
	// 사과 1 빈칸 0 벽 -1 // 상하좌우 이동 // 이동시 장애물로 바뀜.
	input();
	dfs(r, c, 0);
	if (flag == 1) {
		cout << 1;
	}
	else cout << 0;
	return 0;
}