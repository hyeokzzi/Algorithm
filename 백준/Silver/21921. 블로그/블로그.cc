#include<iostream>
using namespace std;
int arr[250001];
int X, N;
void input() {
	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}
void solution() {
	int max_value = 0;
	int max_cnt = 0;

	for (int i = 0; i <= N - X + 1; i++) {
		int value = arr[i + X] - arr[i];
		if (max_value <= value) {
			if (value == max_value) {
				max_cnt++;
			}
			else {
				max_value = value;
				max_cnt = 1;
			}
		}
	}
	if (max_value == 0) {
		cout << "SAD";
		return;
	}
	cout << max_value << '\n' << max_cnt;

}

int main() {
	input();
	solution();
	return 0;
}

