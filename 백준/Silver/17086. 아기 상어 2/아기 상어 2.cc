#include<iostream>
#include<queue>
using namespace std;
int arr[51][51];
int N, M;
int bfs(int y, int x) {
	queue<pair<int, int>> que;
	bool visited[51][51] = { false };
	visited[y][x] = true;
	que.push({ y,x });

	int tx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int ty[8] = { -1, -1, 0 , 1, 1, 1 ,0, -1 };
	int cnt = 1;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int ax = que.front().second;
			int ay = que.front().first;
			que.pop();
			for (int j = 0; j < 8; j++) {
				int dx = ax + tx[j];
				int dy = ay + ty[j];
				if (dx <= 0 || dx > M || dy <= 0 || dy > N) continue;
				if (visited[dy][dx] == true) continue;
				if (arr[dy][dx] == 1) return cnt;
				visited[dy][dx] = true;
				que.push({ dy, dx });
			}
		}
		cnt++;
	}
	return 0;
}




int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int max_num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1) continue;
			max_num = max(bfs(i, j), max_num);
		}
	}
	cout << max_num;



	return 0;
}