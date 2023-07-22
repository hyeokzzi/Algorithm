#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char arr[12][6];
bool visited[12][6];
int dx[4] = { 0, 1, 0 ,-1 };
int dy[4] = { -1, 0, 1, 0 };
void input() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
}
int dfs(int y, int x, char color) {
	visited[y][x] = true;
	int sum = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || tx > 5 || ty < 0 || ty > 11) continue;
		if (visited[ty][tx]) continue;
		if (arr[ty][tx] == color) {
			sum += dfs(ty, tx, color);
		}
	}
	visited[y][x] = false;
	return sum;
}
void visit_dfs(int y, int x, char color) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || tx > 5 || ty < 0 || ty > 11) continue;
		if (visited[ty][tx]) continue;
		if (arr[ty][tx] == color) {
			visit_dfs(ty, tx, color);
		}
	}
}

void moving() {
	for (int j = 0; j < 6; j++) {
		vector<char> save;
		for (int i = 11; i >= 0; i--) {
			if (!visited[i][j]) save.push_back(arr[i][j]);
		}
		int size = save.size();
		for (int i = 11; i > 11 - size; i--) {
			arr[i][j] = save[11 - i];
		}
		for (int i = 11 - size; i >= 0; i--) {
			arr[i][j] = '.';
		}
	}
}
int solve() {
	int count_move = 0;
	while (1) {
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && !visited[i][j]) {
					int t = dfs(i, j, arr[i][j]);
					if (t >= 4) {
						cnt++;
						visit_dfs(i, j, arr[i][j]);
					}
				}
			}
		}
		if (cnt > 0) {
			count_move++;
			moving();
		}
		else break;
	}
	return count_move;
}

int main() {
	input();
	cout << solve();

	return 0;
}