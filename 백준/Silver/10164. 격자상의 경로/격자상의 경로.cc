#include<iostream>
#include<queue>
using namespace std;
int N, M, K, arr[16][16];
long long func(int b, int a, int y, int x) {
	long long dp[16][16] = { 0, };
	dp[b][a] = 1;
	for (int i = b; i <= y; i++) {
		for (int j = a; j <= x; j++) {
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[y][x];
}




int main() {
	cin >> N >> M >> K;
	int num = 1;
	int ty = 0;
	int tx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (num == K) {
				ty = i;
				tx = j;
			}
			num++;
		}
	}
	if (K == 0) {
		cout << func(1, 1, N, M);
	}
	else {

		cout << func(1, 1, ty, tx) * func(ty, tx, N, M);
	}

	return 0;
}