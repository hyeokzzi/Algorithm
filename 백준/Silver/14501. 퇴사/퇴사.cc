#include<iostream>
#include<vector>
std::vector<std::pair<int, int>> arr;

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int num1, num2;
		std::cin >> num1 >> num2;
		arr.push_back(std::make_pair(num1, num2));
	}

	int dp[16] = { 0, };
	for (int i = 1; i <= N; i++) {
		int T = arr[N - i].first;
		int P = arr[N - i].second;
		if (i >= T) {
			dp[i] = std::max(P + dp[i - T], dp[i - 1]);
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	std::cout << dp[N];
	return 0;
}