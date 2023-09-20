#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long sum = 0;
	int start_idx = 1;
	int end_idx = 1;
	int cnt = 1;
	// 투포인터
	while (1) {
		if (start_idx == N) break;
		while (end_idx < N && sum < N) {
			sum += end_idx;
			end_idx++;
		}
		if (sum == N) cnt++;
		sum -= start_idx;
		start_idx++;
	}

	cout << cnt;

	return 0;
}