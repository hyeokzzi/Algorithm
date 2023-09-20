#include<iostream>
using namespace std;
int alpha[4];
int S, P;
string s;
void input() {
	cin >> S >> P >> s;
	for (int i = 0; i < 4; i++) {
		cin >> alpha[i];
	}
}

int change_index(char a) {
	int t = 0;
	switch (a) {
	case 'A':
		t = 0;
		break;
	case 'C':
		t = 1;
		break;
	case 'G':
		t = 2;
		break;
	case 'T':
		t = 3;
		break;
	default:
		t = -1;
		break;
	}
	return t;
}

void solution() {
	int len = s.length();
	int temp[4] = { 0, };
	int flag = 0;
	// 초기 글자 수
	for (int i = 0; i < P; i++) {
		int idx = change_index(s[i]);
		if (idx == -1) flag++;
		else temp[idx]++;
	}

	// 윈도우
	int start_idx = 0;
	int end_idx = P - 1;
	int cnt = 0;
	while (end_idx < S) {
		int check = 0;
		if (flag == 0) {
			for (int i = 0; i < 4; i++) {
				if (alpha[i] <= temp[i])check++;
			}
			if (check == 4) cnt++;
		}
		int start_i = change_index(s[start_idx]);
		start_idx++;
		end_idx++;
		int end_i = change_index(s[end_idx]);
		if (start_i == -1) flag--;
		else {
			temp[start_i]--;
		}

		if (end_i == -1) flag++;
		else temp[end_i]++;
	}
	cout << cnt;

}


int main() {
	
	input();
	solution();

	return 0;
}