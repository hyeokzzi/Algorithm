#include<iostream>
using namespace std;
int main() {

	int N, K;
	cin >> N >> K;
	int arr[11][11];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int ans[101][101];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int t = 0; t < K; t++) {
				for (int p = 0; p < K; p++) {
					ans[K * i + t][K * j + p] = arr[i][j];
				}
			}
		}
	}

	for (int i = 0; i < N * K; i++) {
		for (int j = 0; j < N * K; j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}