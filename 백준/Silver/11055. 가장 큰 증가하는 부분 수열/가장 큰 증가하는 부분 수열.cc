#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}


	for (int i = 1; i <= N; i ++ ) {
		int max_sum = 0;
		for (int j = i; j >= 1; j--) {
			if (arr[i] > arr[j]) max_sum = max(max_sum, dp[j]);
		}
		dp[i] = max_sum + arr[i];
	}
	int max_sum = 0;
	for (int i = 1; i <= N; i++) {
		max_sum = max(max_sum, dp[i]);
	}
	cout << max_sum;
	return 0;
}