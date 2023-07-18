#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int visited[101][101];
int arr[101][101];
queue<pair<int, int>> que;
int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0 , 1, 0 };
void bfs() {
	int year = 1;
	while (1) {
		// 시작 시, 기본 셋팅
		bool visited[101][101] = { false };
		que.push({ 1,1 });
		visited[1][1] = true;
		// BFS
		while (!que.empty()) {
			int size = que.size();
			for (int k = 0; k < size; k++) {
				int x = que.front().second;
				int y = que.front().first;
				que.pop();
				for (int i = 0; i < 4; i++) {
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx < 1 || tx > M || ty < 1 || ty > N) continue;
					if (visited[ty][tx]) continue;
					visited[ty][tx] = true;
					if (arr[ty][tx] == 0) {
						que.push({ ty,tx });
					}
				}
			}
		}
		// 삭제
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					if (visited[i][j]) {
						arr[i][j] = 0;
					}
				}
			}
		}
		// cnt는 이전상황 총 치즈 갯수
		int current = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] == 1) {
					current++;
				}
			}
		}
		if (current == 0) {
			cout << year << '\n' << cnt;
			return;
		}
		year++;
		// 확인
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	bfs();

	return 0;
}