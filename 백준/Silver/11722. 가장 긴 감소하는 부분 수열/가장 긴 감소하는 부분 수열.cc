#include<iostream>
using namespace std;
int N, arr[1001], ans[1001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	for (int i = 1; i < N; i++) {
		int cnt = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j]) {
				ans[i] = max(ans[j] + 1, ans[i]);
			}
		}
	}

	int max_cnt = 0;
	for (int i = 0; i < N; i++) {
		max_cnt = max(max_cnt, ans[i]);
	}
	cout << max_cnt + 1;

}

int main() {
	input();
	solution();

	return 0;
}