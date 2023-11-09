#include<iostream>
#include<queue>
using namespace std;
int N, M, K, arr[16][16];
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
int func(int b, int a, int y, int x) {
	int cnt = 0;
	queue<pair<int, int>> que;
	que.push({ b,a });
	while (!que.empty()) {
		int ax = que.front().second;
		int ay = que.front().first;
		que.pop();
		for (int i = 0; i < 2; i++) {
			int tx = ax + dx[i];
			int ty = ay + dy[i];
			if (tx > x || ty > y) continue;
			if (tx == x && ty == y) cnt++;
			else que.push({ ty,tx });
		}
	}
	return cnt;
}




int main() {
    ios_base::sync_with_stdio(0);
    
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] = i * M + j;
		}
	}
	if (K == 0) {
		cout << func(0, 1, N - 1, M);
	}
	else {
		int ty = K / M;
		int tx = K % M;
		cout << func(0, 1, ty, tx) * func(ty, tx, N - 1, M);
	}
	return 0;
}