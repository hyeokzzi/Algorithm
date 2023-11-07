#include<iostream>
using namespace std;
int arr[51];
bool dp[51][1001];
int N, S, M;

void input() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == true) {
				if (j + arr[i] <= M) dp[i][j + arr[i]] = true;
				if (j - arr[i] >= 0) dp[i][j - arr[i]] = true;
			}
		}
	}
	for (int i = M; i >= 0; i--) {
		if (dp[N][i] == true) {
			cout << i;
			return;
		}
	}
	cout << "-1";
}


int main() {
	input();
	solution();

	return 0;
}