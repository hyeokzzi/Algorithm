#include<iostream>
using namespace std;


int main() {
	string s;
	cin >> s;
	int cnt_u = 0;
	int cnt_dp = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == 'U' || s[i] == 'C') {
			cnt_u++;
		}
		else{
			cnt_dp++;
		}
	}
	if (cnt_dp >= 1) {
		if (cnt_u > (cnt_dp / 2) + (cnt_dp % 2)) {
			cout << "UDP";
		}
		else {
			cout << "DP";
		}
	}
	else {
		cout << "U";
	}
	return 0;
}