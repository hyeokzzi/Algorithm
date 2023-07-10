#include<iostream>
using namespace std;
int R, C; // 세로 가로
char arr[21][21];
bool alpha[26] = { false };

int max_cnt = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };


void dfs(int y, int x, int cnt) {

	max_cnt = max(max_cnt, cnt);
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		int idx = arr[ty][tx] - 'A';
		if (tx < 1 || tx > C || ty < 1 || ty > R) continue;
		if (alpha[idx] == true) continue;
		alpha[idx] = true;
		dfs(ty, tx, cnt + 1);
		alpha[idx] = false;
	}
}


int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= C; j++) {
			arr[i][j] = s[j - 1];
		}
	}
	alpha[arr[1][1] - 'A'] = true;
	dfs(1, 1, 1);
	
	cout << max_cnt;
	return 0;
}