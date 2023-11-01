#include<iostream>
#include<algorithm>
using namespace std;
int N, X, arr[100001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> X;
}

void solution() {
	sort(arr, arr + N);
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] + arr[j] == X)  cnt++;
			else if (arr[i] + arr[j] > X) break;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solution();
	return 0;
}