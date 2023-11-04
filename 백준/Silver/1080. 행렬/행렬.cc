#include<iostream>
using namespace std;
int N, M, arr[51][51];
int ans[51][51];
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			ans[i][j] = s[j - 1] - '0';
		}
	}
}
void func(int y, int x) {
	for (int i = y; i <= y + 2; i++) {
		for (int j = x; j <= x + 2; j++) {
			arr[i][j] = (arr[i][j] + 1) % 2;
		}
	}
}


void solution() {
	int cnt = 0;
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 2; j++) {
			if (arr[i][j] != ans[i][j]) {
				func(i, j);
				cnt++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] != ans[i][j]) {
				cout << "-1";
				return;
			}
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}