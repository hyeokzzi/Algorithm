#include<iostream>
#include<queue>
using namespace std;
int arr[101][101];
queue<pair<int, int>> que;
int visited[101][101] = { 0, };
int N, M;
void bfs() {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front().second;
			int y = que.front().first;
			que.pop();
			for (int j = 0; j < 4; j++) {
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx <= 0 || tx > M || ty <= 0 || ty > N) continue;
				if (arr[ty][tx] == 1) {
					if (visited[ty][tx] == 0 || (visited[ty][tx] > visited[y][x] + 1)) {
						visited[ty][tx] = visited[y][x] + 1;
						que.push({ ty, tx });
					}
				}
			}
		}
	}


}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		char num[102];
		cin >> num;
		for (int j = M; j > 0; j--) {
			arr[i][j] = num[j - 1] - '0';
		}
	}
	visited[1][1] = 1;
	que.push({ 1,1 });
	bfs();
	cout << visited[N][M];
	return 0;
}