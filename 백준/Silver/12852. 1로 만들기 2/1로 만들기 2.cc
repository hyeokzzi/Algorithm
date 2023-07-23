#include<iostream>
using namespace std;
int dp[1000001] = { 0, };
int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	int idx = N ;
	cout << dp[N] - 1 << '\n';
	while (1) {
		cout << idx << " ";
		// 3으로 나눌 때, 2로 나눌 때, 1을 뺄 때 가장 최솟값의 idx 구하기
		if (idx == 1) break;
		int tmp = idx - 1;
		if (idx % 3 == 0 && dp[tmp] > dp[idx / 3]) {
			tmp = idx / 3;
		}
		if (idx % 2 == 0 && dp[tmp] > dp[idx / 2]) {
			tmp = idx / 2;
		}
		idx = tmp;
	}
	return 0;
}