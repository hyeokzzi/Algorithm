#include<iostream>
using namespace std;
long long dp[1000001];
int main() {
	long long N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (long long i = 4; i < 1000001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}
	cin >> N;
	while (N--) {
		long long num;
		cin >> num;
		cout << dp[num] << '\n';
	}
	return 0;
}