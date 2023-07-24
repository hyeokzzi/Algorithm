#include<iostream>
#include<vector>
using namespace std;
int dp[1500100];
int N;
vector<pair<int, int>> arr; // t p

void input() {
	cin >> N;
	arr.push_back({ 0, 0 });
	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;
		arr.push_back({ t,p });
	}
}

void solution() {
	
	for (int i = N; i >= 1; i--) {
		// 상담 가능일을 초과할 경우
		if (arr[i].first + i - 1 > N) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], arr[i].second + dp[i + arr[i].first]);
		}
		
	}
	cout << dp[1];


}

int main() {
	input();
	solution();
	return 0;
}

