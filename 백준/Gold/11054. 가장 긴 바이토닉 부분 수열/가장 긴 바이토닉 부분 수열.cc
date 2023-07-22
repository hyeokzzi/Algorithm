#include<iostream>
using namespace std;
int N;
int arr[1001];
int dp[3][1001] = { 0, };
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int idx = 0;
	// 커지면서 최장 길이수열
	
	for (int i = 1; i <= N; i++) {
		for (int j = i; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				dp[idx][i] = max(dp[idx][i], dp[idx][j]);
			}
		}
		dp[idx][i]++;
	}
	idx++;
	// 작아지는 최장 길이수열
	for (int i = N ; i > 0; i--) {
		for (int j = i; j <= N; j++) {
			if (arr[i] > arr[j]) {
				dp[idx][i] = max(dp[idx][i], dp[idx][j]);
			}
		}
		dp[idx][i]++;
	}
	idx++;

	// 합
	int max_sum = 0;
	for (int i = 1; i <= N; i++) {
		max_sum = max(max_sum, dp[idx - 1][i] + dp[idx - 2][i]);
	}
	cout << max_sum - 1;

}


int main() {
	input();
	solve();

	return 0;
}