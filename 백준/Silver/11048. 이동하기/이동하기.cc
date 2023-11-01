#include<iostream>
#include<queue>
using namespace std;
int N, M;
int arr[1001][1001];
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };
int dp[1001][1001];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1])) + arr[i][j];
		}
	}
	cout << dp[N][M];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	return 0;
}