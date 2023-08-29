#include<iostream>
#include<cstring>
using namespace std;

bool check(string s) {
	
	int len = s.length();
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') break;
		cnt++;
	}
	if (cnt == len) return false;

	int flag_1 = 0; // 자음
	int flag_2 = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			flag_2++;
			flag_1 = 0;
		}
		else {
			flag_1++;
			flag_2 = 0;
		}
		if (flag_1 == 3 || flag_2 == 3) return false;
	}

	for (int i = 1; i < len; i++) {
		if (s[i] == s[i - 1] && (s[i] != 'e' && s[i] != 'o')) return false;
	}
	return true;


}


int main() {
	while (1) {
		string s;
		cin >> s;
		if (s == "end") return 0;

		if (check(s)) {
			cout << '<' << s << "> is acceptable." << '\n';
		}
		else {
			cout << '<' << s << "> is not acceptable." << '\n';
		}
	}

	return 0;
}