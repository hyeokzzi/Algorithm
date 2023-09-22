#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;

	int len = s.length();

	for (int i = 0; i < len; i++) {
		int min_num = s[i] - '0';
		int min_idx = i;
		for (int j = i + 1; j < len; j++) {
			if (min_num < s[j] - '0') {
				min_num = s[j] - '0';
				min_idx = j;
			}
		}

		if (i != min_idx) {
			char tmp = s[i];
			s[i] = s[min_idx];
			s[min_idx] = tmp;
		}
	}

	cout << s;

	return 0;
}