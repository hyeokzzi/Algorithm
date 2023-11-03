#include<iostream>
using namespace std;
int N, K;
int main() {
	string s;
	cin >> s;

	int idx = 0;
	int num = 0;
	int len = s.length();
	while (1) {
		num += s[idx++] - '0';
		if (num * 10 > 10 || idx == len - 1) break;
		else num *= 10;
	}
	int num2 = 0;
	while (1) {
		num2 += s[idx++] - '0';
		if (num2 * 10 > 10 || idx >= len) break;
		else num2 *= 10;
	}
	cout << num + num2;
	return 0;
}