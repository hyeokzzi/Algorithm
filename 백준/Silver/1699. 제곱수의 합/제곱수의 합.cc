#include<iostream>
#include<cmath>
using namespace std;
int dp[100001];
int main() {
	int N;
	cin >> N;

	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = sqrt(i); j>= 1; j--) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N];

	return 0;
}