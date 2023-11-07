#include<iostream>
using namespace std;
int N, M;
int arr[51][51];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
}
int dx[3] = { 1, 0, 1 };
int dy[3] = { 0 ,1, 1 };
void solution() {
	int size = min(N, M);
	for (int t = size - 1; t >= 0; t--) {
		for (int i = 0; i < N - t; i++) {
			for (int j = 0; j < M - t; j++) {
				int cnt = 0;
				for (int k = 0; k < 3; k++) {
					int tx = j + dx[k] * t;
					int ty = i + dy[k] * t;
					if (arr[ty][tx] == arr[i][j]) cnt++;
				}
				if (cnt == 3) {
					cout << (t + 1) * (t + 1);
					return;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	return 0;
}