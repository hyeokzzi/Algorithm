#include<iostream>
using namespace std;
int arr[101][101];
long long N, visited[101][101];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			visited[i][j] = -1;
		}
	}
}
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

long long solution(int y, int x) {
	visited[y][x] = 0;
	int d = arr[y][x];
	for (int i = 0; i < 2; i++) {
		int tx = x + (dx[i] * d);
		int ty = y + (dy[i] * d);
		if (ty >= N || tx >= N) continue;
		if (visited[ty][tx] != -1) visited[y][x] += visited[ty][tx];
		else visited[y][x] += solution(ty , tx);
	}
	return visited[y][x];
}

int main() {
	input();
	visited[N - 1][N - 1] = 1;
	cout << solution(0, 0);
	return 0;
}