#include<iostream>
#include<deque>
#include<queue>

using namespace std;
string s[4];
deque<int> deq[4];
queue<pair<int,int>> que;
bool rotate_check[4] = { false };
int N;
void input() {
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
		for (int j = 0; j < 8; j++) {
			deq[i].push_back(s[i][j] - '0');
		}
	}
}

bool rotate_cir(int idx, int direction) {
	if (direction == 1) {
		deq[idx].push_front(deq[idx].back());
		deq[idx].pop_back();
	}
	else {
		deq[idx].push_back(deq[idx].front());
		deq[idx].pop_front();
	}
	return true;
}

void func(int idx, int direction) {
	rotate_check[idx] = true;
	if (idx - 1 != -1 && !rotate_check[idx-1] && deq[idx][6] != deq[idx - 1][2]) {
		func(idx - 1, direction * -1);
	}
	if (idx + 1 != 4 && !rotate_check[idx + 1] &&  deq[idx][2] != deq[idx + 1][6]) {
		func(idx + 1, direction * -1);
	}
	rotate_cir(idx, direction);
}

void solution() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			rotate_check[j] = false;
		}
		int num, dir;
		cin >> num >> dir;
		int idx = num - 1;
		int direction = dir;
		func(idx, dir);
	}
	int score = 0;
	int score_board[4] = { 1, 2, 4, 8 };
	for (int i = 0; i < 4; i++) {
		if (deq[i][0] == 1) score += score_board[i];
	}
	cout << score;

}

int main() {
	input();
	solution();
	return 0;
}