#include<iostream>
using namespace std;
int dp[31];
int main() {
	int N;
	cin >> N;

	dp[2] = 3;
	dp[0] = 1;

	for (int i = 4; i <= N; i+=2) {
		for (int j = i; j > 0; j -= 2) {
			if (j != 2) {
				dp[i] += 2 * dp[i - j];
			}
			else if (j == 2) {
				dp[i] += dp[2] * dp[i - j];
			}
		}
	}
	cout << dp[N];
	return 0;
}