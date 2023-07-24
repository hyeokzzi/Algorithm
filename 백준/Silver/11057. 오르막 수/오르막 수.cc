#include<iostream>
using namespace std;
int N;
int dp[1001];
int arr[1001];
int main() {
	
	cin >> N;
	dp[0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[j] = ((dp[j - 1] % 10007) + (dp[j] % 10007)) % 10007;
		}
	}
	cout << dp[9];
	

	return 0;
}