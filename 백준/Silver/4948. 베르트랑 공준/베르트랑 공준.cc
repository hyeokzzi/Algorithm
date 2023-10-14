#include<iostream>
using namespace std;
int arr[250001];
int main() {
	for (int i = 1; i <= 250000; i++) {
		arr[i] = i;
	}
	arr[1] = 0;
	for (int i = 2; i <= 250000; i++) {
		if (arr[i] != i) continue;
		for (int j = i * 2; j <= 250000; j += i) arr[j] = 0;
	}

	int N;
	while (1) {
		cin >> N;
		if (N == 0) break;
		int cnt = 0;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (arr[i] == i) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}