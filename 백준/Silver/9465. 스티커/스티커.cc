#include<iostream>

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		// 입력
		int N;
		std::cin >> N;
		int arr[2][100002] = { 0, };
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < N; k++) {
				std::cin >> arr[j][k];
			}
		}

		// 처리
		for (int k = N - 2; k >= 0; k--) {
			for (int j = 0; j < 2; j++) {
				if (arr[(j + 1) % 2][k + 1] > arr[(j + 1) % 2][k + 2]) {
					arr[j][k] = arr[j][k] + arr[(j + 1) % 2][k + 1];
				}
				else {
					arr[j][k] = arr[j][k] + arr[(j + 1) % 2][k + 2];
				}
			}
		}

		if (arr[0][0] > arr[1][0]) {
			std::cout << arr[0][0] << '\n';
		}
		else {
			std::cout << arr[1][0] << '\n';
		}
	}





	return 0;
}