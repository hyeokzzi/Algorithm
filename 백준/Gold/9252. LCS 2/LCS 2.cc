#include<iostream>
#include<vector>
using namespace std;
string s1, s2;
int dp[1001][1001];

// ★★★★ 최장수열 문자 출력 방법 ★★★★
vector<char> vec;
void getText(int r, int c) {
	if (r == 0 || c == 0) return;
	if (s1[r - 1] == s2[c - 1]) {
		vec.push_back(s1[r - 1]);
		getText(r - 1, c - 1);
	}
	else {
		if (dp[r - 1][c] > dp[r][c - 1]) getText(r - 1, c);
		else getText(r, c - 1);
	}
}



int main() {
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// 어떻게 출력?? ==> ★
	int size = dp[len1][len2];
	getText(len1, len2);
	cout << size << '\n';
	for (int i = size - 1; i >= 0; i--) {
		cout << vec[i];
	}
	return 0;
}