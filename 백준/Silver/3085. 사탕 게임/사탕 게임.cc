#include<iostream>
using namespace std;
int N, max_cnt;
char arr[52][52];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j];
		}
	}
}
void swap(int y, int x, int ty, int tx) {
	int temp = arr[y][x];
	arr[y][x] = arr[ty][tx];
	arr[ty][tx] = temp;
}
int func(int y, int x, int dir) {
	int temp = arr[y][x];
	int cnt = 0;
	while (temp == arr[y + dy[dir]][x + dx[dir]]) {
		y += dy[dir];
		x += dx[dir];
		cnt++;
	}
	return cnt;
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx < 0 || tx >= N || ty < 0 || ty >= N) continue;
				if (arr[i][j] != arr[ty][tx]) {
					swap(i, j, ty, tx);
					max_cnt = max(max_cnt, func(i, j, k) + func(i, j, (k + 2) % 4) + 1);
					max_cnt = max(max_cnt, func(i, j, (k + 1) % 4) + func(i, j, (k + 3) % 4) + 1);
					swap(i, j, ty, tx);
				}
				else {
					max_cnt = max(max_cnt, func(i, j, k) + func(i, j, (k + 2) % 4) + 1);
					max_cnt = max(max_cnt, func(i, j, (k + 1) % 4) + func(i, j, (k + 3) % 4) + 1);
				}
			}
		}
	}
	cout << max_cnt;
}


int main() {
	input();
	solution();
	return 0;
}