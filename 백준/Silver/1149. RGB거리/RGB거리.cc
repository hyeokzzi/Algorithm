#include<iostream>
int rgb[1002][3];

int main() {
	// 입력
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int red, green, blue;
		std::cin >> red >> green >> blue;
		rgb[i][0] = red;
		rgb[i][1] = green;
		rgb[i][2] = blue;
	}

	// 처리

	// 인덱스
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int min = 210000000;
			// 이전 인덱스와의 합 중 최소값으로 치환
			for (int k = 0; k < 3; k++) {
				if (k != j) {
					if (rgb[i][j] + rgb[i - 1][k] < min) {
						min = rgb[i][j] + rgb[i - 1][k];
					}
				}
			}
			rgb[i][j] = min;
		}
	}

	// 출력
	int total_min = rgb[N-1][0];
	for (int i = 1; i < 3; i++) {
		if (total_min > rgb[N-1][i]) {
			total_min = rgb[N-1][i];
		}
	}
	std::cout << total_min;

	return 0;
}

