#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[10001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int sum = 0;
	int cnt = 0;
	int end = 0;
	for(int i = 0; i < N; i++){
		while (end < N && sum < M) {
			sum += arr[end];
			end++;
		}
		if (sum == M) cnt++;
		sum -= arr[i];
	}
	cout << cnt;

}

int main() {
	input();
	solution();

	return 0;
}