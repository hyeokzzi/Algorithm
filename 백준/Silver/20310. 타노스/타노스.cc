#include<iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	int len = s.length();
	int zero_cnt = 0;
	int one_cnt = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] - '0' == 0) zero_cnt++;
		else one_cnt++;
	}

	int zero_del = 0;
	int one_del = 0;
	for (int i = 0; i < len; i++) {
		if (one_del == one_cnt / 2) break;
		if (s[i] == '1') {
			one_del++;
			s[i] = '.';
		}
	}
	for (int i = len - 1; i >= 0; i--) {
		if (zero_del == zero_cnt / 2) break;
		if (s[i] == '0') {
			zero_del++;
			s[i] = '.';
		}
	}

	for (int i = 0; i < len; i++) {
		if (s[i] != '.') cout << s[i];
	}

	return 0;
}