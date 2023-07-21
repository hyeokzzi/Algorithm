#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	// R
	int flag = 0;
	int cnt_R = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == 'R' && flag == 1) {
			cnt_R++;
		}
		if (s[i] == 'B') flag = 1;
	}
	// B
	flag = 0;
	int cnt_B = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == 'B' && flag == 1) {
			cnt_B++;
		}
		if (s[i] == 'R') flag = 1;
	}
	cout << min(cnt_B, cnt_R);
	return 0;
}