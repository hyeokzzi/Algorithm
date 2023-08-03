#include<iostream>
#include<vector>
using namespace std;
int M, N;
int arr[1000001];
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int max_cur = 0;
	int end_idx = 1000000000;
	int start_idx = 1;
	int cur = (end_idx + start_idx) / 2;
	int flag = 0;
	while (1) {
		// 된다 안된다
		if (end_idx == start_idx + 1 || end_idx == start_idx) break;
		int cnt = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (cnt >= M) break;
			cnt += arr[i] / cur;
		}
		// cur 값 높여야 돼
		if (cnt >= M) {
			max_cur = max(max_cur, cur);
			start_idx = cur;
		}
		else {
			end_idx = cur;

		}
		cur = (end_idx + start_idx) / 2;
	}
	for (int k = start_idx; k <= end_idx; k++) {
		int cnt = 0;
		cur = k;
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i] < cur) break;
			cnt += arr[i] / cur;
		}
		// cur 값 높여야 돼
		if (cnt >= M) {
			max_cur = max(max_cur, cur);
		}
	}

	cout << max_cur;
	return 0;
}