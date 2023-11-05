#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> arr;
int dp[101];
int N;

void input() {
	cin >> N;
	while (N--) {
		int st, en;
		cin >> st >> en;
		arr.push_back({ st,en });
	}

}

void solution() {
	sort(arr.begin(), arr.end());
	int size = arr.size();
	dp[0] = 1;
	for (int i = 1; i < size; i++) {
		dp[i] = 1;
		for (int j = i; j >= 0; j--) {
			if (arr[i].second > arr[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

	}
	int max_cnt = 0;
	for (int i = 0; i < size; i++) {
		max_cnt = max(max_cnt, dp[i]);
	}
	cout << size - max_cnt;

}

int main() {
	input();
	solution();
	return 0;
}