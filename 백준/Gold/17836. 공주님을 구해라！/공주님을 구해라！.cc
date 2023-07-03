#include<iostream>
#include<queue>
using namespace std;
int arr[101][101] = { 0, };
int visited[101][101] = { 0, };
queue<pair<int, int>> que;
int N, M;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs() {
	que.push({ 1,1 });
	visited[1][1] = 1;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front().second;
			int y = que.front().first;
			que.pop();
			for (int i = 0; i < 4; i++) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx <= 0 || tx > M|| ty <= 0 || ty > N) continue;
				if (arr[ty][tx] != 1) {
					if (visited[ty][tx] == 0) {
						visited[ty][tx] = visited[y][x] + 1;
						que.push({ ty, tx });
					}
					else {
						int distance = visited[y][x] + 1;
						if (distance < visited[ty][tx]) {
							visited[ty][tx] = distance;
							que.push({ ty, tx });
						}
					}
				}
				if (visited[ty][tx] == 0 && arr[ty][tx] != 1) {
					visited[ty][tx] = visited[y][x] + 1;
					que.push({ ty, tx });
				}

			}
		}
	}
}



int main() {
	cin >> N >> M;
	int time;
	cin >> time;
	int sword_x = -1, sword_y = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				sword_x = j;
				sword_y = i;
			}
		}
	}
	bfs();
	// 도달하지 못한경우



	if (visited[N][M] == 0) {
		if (visited[sword_y][sword_x] != 0) {
			int distance = visited[sword_y][sword_x] - 1 + abs(N - sword_y) + abs(M - sword_x);
			if (distance > time) {
				cout << "Fail";
			}
			else {
				cout << distance;
			}
		}
		else {
			cout << "Fail";
		}
	}
	else {
		int distance = visited[N][M] - 1;
		// 검에 도달했을 때
		if (visited[sword_y][sword_x] != 0) {
			distance = min(distance, visited[sword_y][sword_x] - 1 + abs(N - sword_y) + abs(M - sword_x));
		}
		// 검에 못갔을 때
		if (distance > time) {
			cout << "Fail";
		}
		else {
			cout << distance;
		}


	}

	return 0;
}