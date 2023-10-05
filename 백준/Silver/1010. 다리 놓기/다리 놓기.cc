#include<iostream>
using namespace std;
int T, N, K;
int main(){
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		long long dp[31][31] = { 0, };

		for (int j = 0; j <= K; j++) {
			dp[j][0] = 1;
			dp[j][j] = 1;
			dp[j][1] = j;
		}

		for (int j = 2; j <= K; j++) {
			for (int k = 1; k < j; k++) {
				dp[j][k] = dp[j - 1][k] + dp[j - 1][k - 1];
			}
		}
		cout << dp[K][N] << '\n';
		
	}
	return 0;
}