#include<iostream>
using namespace std;
bool visited[251][251] = { false };
char arr[251][251];
int R, C;
int cnt[2] = { 0 }; // 늑대와 양 숫자 저장.
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int y, int x) {
	visited[y][x] = true;
	// 양 늑대 확인 후 이동
	if (arr[y][x] == 'v') cnt[0]++;
	else if (arr[y][x] == 'k') cnt[1]++;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx <= 0 || tx > C || ty <= 0 || ty > R) continue;
		if (visited[ty][tx] == true) continue;
		dfs(ty, tx);
	}
}


int main() {

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '#') visited[i][j] = true;
		}
	}
	int wolf = 0, sheep = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (visited[i][j] == false && (arr[i][j] == '.' || arr[i][j] == 'v' || arr[i][j] == 'k')) {
				cnt[0] = 0;
				cnt[1] = 0;
				dfs(i,j);
				if (cnt[0] >= cnt[1])
				{
					wolf += cnt[0];
				}
				else {
					sheep += cnt[1];
				}
			}
		}
	}
	cout << sheep << " " << wolf;

	return 0;
}