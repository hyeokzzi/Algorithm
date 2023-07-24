#include<iostream>
#include<vector>
using namespace std;
int N;
int arr[1001];
int dp[1001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	dp[N] = 1;
	for (int i = N - 1; i >= 1; i--) {
		int max_sum = 0;
		for (int j = i; j <= N; j++) {
			if (arr[j] > arr[i]) max_sum = max(max_sum, dp[j]);
		}
		dp[i] = max_sum + 1;
	}

	int max_idx = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[max_idx] < dp[i]) {
			max_idx = i;
		}
	}
	// max_idx는 가장 긴 증가하는 부분 수열에 시작
	cout << dp[max_idx] << '\n' << arr[max_idx] << " ";
	int tmp = arr[max_idx];

	for (int i = max_idx; i <= N; i++) {
		if (arr[i] > tmp && dp[i] == dp[max_idx] - 1) {
			cout << arr[i] << " ";
			tmp = arr[i];
			dp[max_idx]--;
		}
	}
}


int main() {
	input();
	solution();
	return 0;
}