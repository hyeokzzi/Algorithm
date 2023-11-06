#include<iostream>
using namespace std;
int value[1001];
int dp[1001];
int N;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		dp[i] = i * value[1];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			dp[j] = min(dp[j], dp[j - i] + value[i]);
		}
	}
	cout << dp[N];
}

int main() {
	input();
	solution();
	return 0;
}