#include<iostream>
using namespace std;
int dp[5001];
int arr[5001];
string s;
int main() {
	if(cin >> s);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '0') {
			if (i > 0 && ((s[i - 1] - '0') > 2 || s[i - 1] == '0')) {
				cout << "0";
				return 0;
			}
			else if (i == 0) {
				cout << "0";
				return 0;
			}
		}
		arr[i + 1] = s[i] - '0';
	}
	dp[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (arr[i] == 0) {
			if (i == 2) dp[i] = 1;
			else dp[i] = dp[i - 2];
			dp[i - 2] = 0;
		}
		else {
			if ((arr[i-1] != 0) && (arr[i - 1] * 10) + arr[i] <= 26) {
				if (i == 2) dp[i] = dp[i - 1] + 1;
				else dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
	}
	cout << dp[len] ;


	return 0;
}