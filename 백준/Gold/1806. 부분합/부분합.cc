#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[100001];
int min_dist = 100001;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int end = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		while (end < N && sum < M) {
			sum += arr[end];
			end++;
		}
		if (end == N && sum < M) break;
		min_dist = min(min_dist, end - i);
		sum -= arr[i];
	}
	if (min_dist == 100001) cout << "0";
	else cout << min_dist;
	return;
}

int main() {

	input();
	solution();

	return 0;
}