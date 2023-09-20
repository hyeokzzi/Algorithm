#include<iostream>
using namespace std;
int N, M;
long long cnt = 0;
long long arr[1000001];
long long rem[1001];



void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		arr[i] += arr[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		arr[i] %= M;
		rem[arr[i]]++;
	}

}

void solution() {
	cnt += rem[0];
	for (int i = 0; i < M; i++) {
		if (rem[i] > 1) {
			cnt += ((rem[i] * (rem[i] - 1)) / 2);
		}
	}
	cout << cnt;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solution();

	return 0;
}