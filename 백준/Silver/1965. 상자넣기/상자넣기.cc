#include<iostream>
using namespace std;
int N, dp[1001], arr[1001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = i; j >= 0; j--) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
		cnt = max(cnt, dp[i]);
	}
	cout << cnt;
	

	return 0;
}