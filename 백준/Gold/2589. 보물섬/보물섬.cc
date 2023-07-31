#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
char arr[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int visited[51][51];
int max_visited = 0;
queue<pair<int, int>> que;
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

void func() {
	while (!que.empty()) {
		int size = que.size();
		for (int k = 0; k < size; k++) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			for (int i = 0; i < 4; i++) {
				int ty = y + dy[i];
				int tx = x + dx[i];
				if (tx < 1 || tx > M || ty < 1 || ty > N) continue;
				if (arr[ty][tx] == 'W') continue;
				if (visited[ty][tx] == 0 || (visited[ty][tx] != 0 && visited[ty][tx] > visited[y][x] + 1))
				{
					visited[ty][tx] = visited[y][x] + 1;
					max_visited = max(max_visited, visited[ty][tx]);
					que.push({ ty,tx });
				}
			}
		}
	}
}



void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 'L') {
				memset(visited, 0, sizeof(visited));
				visited[i][j] = 1;
				que.push({ i,j });
				func();
			}
		}
	}
}


int main() {

	input();
	solution();
	cout << max_visited - 1;
	return 0;
}