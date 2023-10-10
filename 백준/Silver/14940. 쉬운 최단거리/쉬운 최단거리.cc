#include<iostream>
#include<queue>
using namespace std;
int N, M;
int arr[1001][1001];
int visited[1001][1001];
int start_x, start_y;
queue<pair<int, int>> que;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0 , -1 , 0 ,1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				start_x = j;
				start_y = i;
			}
		}
	}
}

void bfs() {

}

void solution() {
	que.push({ start_y, start_x });
	visited[start_y][start_x] = 1;

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front().second;
			int y = que.front().first;
			que.pop();

			for (int j = 0; j < 4; j++) {
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || tx >= M || ty < 0 || ty >= N) continue;
				if (arr[ty][tx] == 0 || visited[ty][tx] != 0) continue;
				visited[ty][tx] = visited[y][x] + 1;
				que.push({ ty, tx });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) cout << visited[i][j] << " ";
			else {
				cout << visited[i][j] - 1 << " ";
			}
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}