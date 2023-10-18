#include<iostream>
using namespace std;
int open_cnt;
int main() {
	string s;
	cin >> s;

	int len = s.length();
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') open_cnt++;
		else if (s[i] == ')') {
			// 레이저
			open_cnt--;
			if (s[i - 1] == '(') {
				cnt += open_cnt;
			}
			else cnt++;
		}
	}
	cout << cnt;

	return 0;
}