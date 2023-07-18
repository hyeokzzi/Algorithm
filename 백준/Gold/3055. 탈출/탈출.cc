#include<iostream>
#include<queue>
using namespace std;
int R, C;
char arr[51][51];
int visited[51][51];
queue<pair<int, int>> que;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };


void bfs() {

	while (!que.empty()) {
		// 레벨당 물 처리
		bool water[51][51] = { 0, };
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (arr[i][j] == '*' &&  !water[i][j]) {
					water[i][j] = true;
					for (int k = 0; k < 4; k++) {
						int tx = j + dx[k];
						int ty = i + dy[k];
						if (tx <1 || tx > C || ty < 1 || ty > R) continue;
						if (arr[ty][tx] == 'X' || arr[ty][tx] == 'D' || arr[ty][tx] == '*') continue;
						arr[ty][tx] = '*';
						water[ty][tx] = true;
					}
				}
			}
		}



		// bfs 처리
		int size = que.size();
		for (int k = 0; k < size; k++) {
			int x = que.front().second;
			int y = que.front().first;
			que.pop();
			for (int i = 0; i < 4; i++) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx <1 || tx > C || ty < 1 || ty > R) continue;
				if (visited[ty][tx] != 0 || arr[ty][tx] == 'X' || arr[ty][tx] == '*') continue;
				visited[ty][tx] = visited[y][x] + 1;
				if (arr[ty][tx] == 'D') return;
				que.push({ ty,tx });
			}
		}
	}



}


int main() {
	cin >> R >> C;
	int start_x = 0, start_y = 0;
	int dest_x = 0, dest_y = 0;
	for (int i = 1; i <= R; i++){
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			arr[i][j + 1] = s[j];
			if (arr[i][j + 1] == 'S') {
				start_x = j + 1;
				start_y = i;
			}
			if (arr[i][j + 1] == 'D') {
				dest_x = j + 1;
				dest_y = i;
			}
		}
	}

	// 처리
	visited[start_y][start_x] = 1;
	que.push({ start_y, start_x });
	bfs();

	if (visited[dest_y][dest_x] == 0) {
		cout << "KAKTUS";
	}
	else {
		cout << visited[dest_y][dest_x] - 1;
	}

	return 0;
}