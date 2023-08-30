#include<iostream>
using namespace std;
string s[1000];
int N;
int heart_x = 0;
int heart_y = 0;
void func1(int idx) {
	int left = 0;
	int right = 0;
	int flag = 0;

	int len = s[idx].length();
	for (int i = 0; i < len; i++) {
		if (s[idx][i] == '*' && s[idx - 1][i] == '*' && s[idx + 1][i] == '*') {
			heart_x = i;
			heart_y = idx;
			flag = 1;
			continue;
		}
		if (s[idx][i] == '*' && flag == 0) left++;
		if (s[idx][i] == '*' && flag == 1) right++;
	}
	cout << heart_y + 1 << " " << heart_x + 1 << '\n';
	cout << left << " " << right << " ";

	return;
}

void func2(int idx) {
	int left = 0;
	int right = 0;
	int flag = 0;
	int len = s[idx].length();
	for (int i = 0; i < len; i++) {
		if (s[idx][i] == '*') {
			int index = idx;
			int cnt = 0;
			while (1) {
				if (index == N) break;
				if (s[index][i] != '*') break;
				cnt++;
				index++;
			}
			if (flag == 0) left = cnt;
			else {
				right = cnt;
				break;
			}
			flag++;
		}
	}
	cout << idx - heart_y - 1 << " " << left << " " << right;
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < N; i++) {
		int len = s[i].length();
		int cnt = 0;
		for (int j = 0; j < len; j++) {
			if (s[i][j] == '*') cnt++;
		}
		if (cnt >= 3) {
			func1(i);
		}
		else if (cnt == 2) {
			func2(i);
			break;
		}
	}

	return 0;
}