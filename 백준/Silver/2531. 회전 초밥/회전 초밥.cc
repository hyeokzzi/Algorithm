#include<iostream>
using namespace std;
int N, d, k, c;
int arr[30001];
int visited[3001] = { 0 };
void input() {
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	
	int cnt = 0;
	int end = 0;
	int max_cnt = 0;
	for (int i = 0; i < N; i++) {
		while (end < i + k) {
			visited[arr[end % N]]++;
			if (visited[arr[end % N]] == 1) cnt++;
			end++;
		}
		// 앞뒤 쿠폰있는지 확인
		if (visited[c] == 0) {
			max_cnt = max(max_cnt, cnt + 1);
		}
		else {
			max_cnt = max(max_cnt, cnt);
		}

		// 앞 제거
		visited[arr[i]]--;
		if (visited[arr[i]] == 0) cnt--;
	}
	cout << max_cnt;
}

int main() {
	input();
	solution();

	return 0;
}