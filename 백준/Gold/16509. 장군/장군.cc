#include<iostream>
#include<queue>
using namespace std;
int visited[10][9] = { 0, };
queue<pair<int, int>> que; //y x


// ↑ → ↓ ←
int dx[4] = { 0, 1, 0 ,-1 };
int dy[4] = { -1, 0 , 1, 0 };
// ↖ ↗ ↘ ↙
int cross_x[4] = { -1,1, 1, -1 };
int cross_y[4] = { -1, -1, 1, 1 };

void bfs() {
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front().second;
			int y = que.front().first;
			que.pop();
			for (int j = 0; j < 4; j++) {
				// 한 방향
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || tx >= 9 || ty < 0 || ty >= 10)continue;
				if (visited[ty][tx] == 200) continue;
				// 방향에 대한 두 방향 & 두 번씩 이동(x2)
				for (int k = 0; k < 2; k++) {
					int fx = tx + (cross_x[(k + j) % 4]);
					int fy = ty + (cross_y[(k + j) % 4]);
					int fx2 = tx + 2 * (cross_x[(k + j) % 4]);
					int fy2 = ty + 2 * (cross_y[(k + j) % 4]);
					if (fx < 0 || fx >= 9 || fy < 0 || fy >= 10)continue;
					if (fx2 < 0 || fx2 >= 9 || fy2 < 0 || fy2 >= 10)continue;
					if (visited[fy][fx] == 200) continue;
					// 처음 갔거나 최소가 아니거나
					if (visited[fy2][fx2] == 0 || visited[fy2][fx2] > visited[y][x] + 1) {
						visited[fy2][fx2] = visited[y][x] + 1;
						que.push({ fy2, fx2 });
					}
				}
			}
		}
	}


}

int main() {

	int sx, sy; // 상
	int kx, ky; // 왕

	cin >> sy >> sx;
	cin >> ky >> kx;

	que.push({ sy, sx });
	visited[sy][sx] = 1;
	visited[ky][kx] = 200;
	bfs();
	if (visited[ky][kx] == 200) {
		cout << -1;
	}
	else {
		cout << visited[ky][kx] - 1;
	}
	return 0;
}