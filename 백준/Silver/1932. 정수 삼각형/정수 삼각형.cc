#include<iostream>
int arr[501][501];
int main() {
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			std::cin >> arr[i][j];
		}
	}
	for (int i = N - 1; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = std::max(arr[i][j] + arr[i + 1][j], arr[i][j] + arr[i + 1][j + 1]);
		}
	}
	std::cout << arr[1][1];
	return 0;
}