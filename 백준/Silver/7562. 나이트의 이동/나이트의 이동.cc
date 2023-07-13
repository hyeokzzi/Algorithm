#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int T, l; // 테스트 케이스, 한변의 길이
int x, y, gx, gy;
queue<pair<int, int>> que;
int visited[300][300] = { 0, };
//int arr[300][300] = { 0, };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
void bfs() {
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front().second;
			int y = que.front().first;
			que.pop();
			for (int j = 0; j < 8; j++) {
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || tx >= l || ty < 0 || ty >= l) continue;
				if (visited[ty][tx] != 0) continue;
				visited[ty][tx] = visited[y][x] + 1;
				if (ty == gy && tx == gx) return;
				que.push({ ty, tx });
			}
		}
	}
}


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> l;
		cin >> x >> y >> gx >> gy;
		memset(visited, 0, sizeof(visited));
		while (!que.empty()) que.pop();
		visited[y][x] = 1;
		que.push({ y,x });
		bfs();
		cout << visited[gy][gx] - 1 << '\n';
	}

	return 0;
}

