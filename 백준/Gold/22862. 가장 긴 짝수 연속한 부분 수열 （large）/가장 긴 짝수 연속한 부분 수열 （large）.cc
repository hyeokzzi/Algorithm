#include<iostream>
using namespace std;
int N, K;
int arr[1000001];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int end = 0;
	int cnt = 0;
	int max_cnt = 0;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		while (end < N && flag <= K) {
			if (arr[end] % 2 == 1) flag++;
			if (flag <= K) max_cnt = max(max_cnt, end - i + 1 - flag);
			end++;
		}

		if (arr[i] % 2 == 1) flag--;
	}
	cout << max_cnt;

}

int main() {

	input();
	solution();

	return 0;
}