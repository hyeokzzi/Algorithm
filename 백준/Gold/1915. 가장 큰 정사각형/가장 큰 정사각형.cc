#include<iostream>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];

int dx[3] = { -1, -1, 0 };
int dy[3] = { 0, -1, -1 };

int main() {
	int N, M;
	cin >> N >> M;
	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) continue;
			int flag = 0;
			int max_flag = 0;
			int max_num = -1;
			int min_num = 1000000;
			for (int k = 0; k < 3; k++) {
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (max_num <= arr[ty][tx]) {
					if (max_num == arr[ty][tx]) max_flag++;
					else {
						max_num = arr[ty][tx];
						max_flag = 1;
					}
				}
				if (arr[ty][tx] >= 1) {
					flag++;
					min_num = min(min_num, arr[ty][tx]);
				}
			}
			if (flag == 3) {
				if (max_flag == 3) arr[i][j] = max_num + 1;
				else arr[i][j] = min_num + 1;
			}
		}
	}
	int max_num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			max_num = max(arr[i][j], max_num);
		}
	}
	cout << max_num * max_num;

	return 0;
}