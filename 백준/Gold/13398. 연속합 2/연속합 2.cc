#include<iostream>
using namespace std;
int N;
int arr[100001];
int dp[2][100001];
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	dp[0][1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
	}

	int max_num = -1000000000;
	for (int i = 1; i <= N; i++) {
		max_num = max(dp[0][i], max_num);
		if (i == 1) continue;
		max_num = max(dp[1][i], max_num);
	}
	cout << max_num;
}

int main() {
	input();
	solution();
	return 0;
}