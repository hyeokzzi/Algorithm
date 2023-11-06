#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char arr[52];
int cnt[26];
vector<char> ans;
int main() {
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		arr[i] = s[i];
		cnt[s[i] - 'A']++;
	}
	int count_odd = 0;
	char odd_letter;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1) {
			count_odd++;
			odd_letter = i + 'A';
		}

	}
	if (count_odd >= 2) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				for (int j = 0; j < cnt[i] / 2; j++) {
					ans.push_back(i + 'A');
				}
			}
		}
		
		int size = ans.size();
		for (int i = 0; i < size; i++) {
			cout << ans[i];
		}
		if (count_odd != 0) cout << odd_letter;
		for (int i = size - 1; i >= 0; i--) {
			cout << ans[i];
		}
		
	}
	return 0;
}