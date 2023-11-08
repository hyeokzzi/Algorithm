#include<iostream>
using namespace std;
int H, W, arr[501];
int value[501];
void input() {
	cin >> H >> W;
	for (int j = 0; j < W; j++) {
		cin >> arr[j];
	}
}

void solution() {
	int sum = 0;
	for (int i = 0; i < W; i++) {
		int left_max = 0;
		for (int j = i-1; j >= 0; j--) {
			left_max = max(left_max, arr[j]);
		}
		int right_max = 0;
		for (int j = i + 1; j < W; j++) {
			right_max = max(right_max, arr[j]);
		}
		if (left_max >= arr[i] && right_max >= arr[i]) {
			sum += min(left_max, right_max) - arr[i];
		}
	}
	cout << sum;
}
int main() {
	input();
	solution();

	return 0;
}