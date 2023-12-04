#include<iostream>
using namespace std;
int arr[2001], N;
int dp[2001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		if (dp[i] == 0) continue;
		for (int j = 1; j <= arr[i]; j++) {
			if (dp[i + j] == 0) {
				dp[i + j] = dp[i] + 1;
			}
			else dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[N - 1] == 0) cout << "-1";
	else cout << dp[N - 1] - 1;
}

int main() {
	input();
	solution();
	return 0;
}