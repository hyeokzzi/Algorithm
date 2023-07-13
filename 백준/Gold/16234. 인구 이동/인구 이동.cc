#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int N, L, R;
int arr[51][51];
bool visited[51][51];
bool flag = false;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int cy, int cx) {
	queue<pair<int, int>> que;
	vector<pair<int, int>> save;
	que.push({ cy,cx });
	save.push_back({ cy,cx });
	int sum = arr[cy][cx];
	visited[cy][cx] = true;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			for (int j = 0; j < 4; j++) {
				int ty = y + dy[j];
				int tx = x + dx[j];
				if (ty < 1 || ty > N || tx < 1 || tx > N) continue;
				if (visited[ty][tx]) continue;
				int num = abs(arr[y][x] - arr[ty][tx]);
				if (num >= L && num <= R) {
					flag = true;
					sum += arr[ty][tx];
					que.push({ ty,tx });
					visited[ty][tx] = true;
					save.push_back({ ty,tx });
				}
			}
		}
	}
	// 동맹국가 값 초기화
	int value = sum / save.size();
	for (auto& e : save) {
		arr[e.first][e.second] = value;
	}
}


int main() {
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	while (1) {
		flag = false;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
				}
			}
		}
		if (flag == false) break;
		cnt++;
	}

	cout << cnt;

	return 0;
}