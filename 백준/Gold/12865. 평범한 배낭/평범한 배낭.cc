#include<iostream>
int weight[101];
int value[101];
int dp[101][100001];
int main() {
	int N, K;
	std::cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		std::cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - weight[i] >= 0) {
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	std::cout << dp[N][K];
	return 0;
}