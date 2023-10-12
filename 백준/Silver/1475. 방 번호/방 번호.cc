#include<iostream>
using namespace std;
int arr[10];
int main() {
	int N;
	cin >> N;

	while (N > 0) {
		int t = N % 10;
		if (t == 6 || t == 9) {
			arr[6]++;
		}
		else arr[t]++;
		N /= 10;
	}
	int max_cnt = 0;
	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			if (arr[i] % 2 == 0) {
				max_cnt = max(max_cnt, arr[i] / 2);
			}
			else {
				max_cnt = max(max_cnt, arr[i] / 2 + 1);
			}
		}
		else max_cnt = max(max_cnt, arr[i]);
	}

	cout << max_cnt;
	return 0;
}