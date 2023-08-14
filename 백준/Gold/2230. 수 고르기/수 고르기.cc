#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int min_diff = 2000000001;
int arr[100001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {

	sort(arr, arr + N);
	int end = 0;
	for (int i = 0; i < N; i++) {
		// 조건을 만족할 때 까지 idx를 증가시킴.
		while (end < N && arr[end] - arr[i] < M) end++;
		// 탈출조건
		if (end == N) break;
		min_diff = min(min_diff, arr[end] - arr[i]);
		if (min_diff == M) {
			cout << min_diff;
			return;
		}
	}
	cout << min_diff;
}

int main() {
	input();
	solution();

	return 0;
}