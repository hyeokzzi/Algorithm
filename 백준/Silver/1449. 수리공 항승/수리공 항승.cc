#include<iostream>
using namespace std;
int arr[2001], N, L;
void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int idx;
		cin >> idx;
		arr[idx] = 1;
	}
}

void solution() {
	int cnt = 0;
	for (int i = 0; i < 1001; i++) {
		if (arr[i] == 1) {
			arr[i] = 0;
			for (int j = i; j < i + L; j++) {
				arr[j] = 0;
			}
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	input();
	solution();

	return 0;
}