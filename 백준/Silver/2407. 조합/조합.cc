#include<iostream>
int arr[101];
int mul[200] = { 1, };
// a가 배열 크기 b가 분모
void find_num(int size, int b) {
	
	while (b != 1) { 
		int flag = 0;

		for (int i = 2; i <= b; i++) {
			if (b % i == 0) {
				for (int j = 0; j < size; j++) {

					if (b % i == 0 && arr[j] % i == 0) {
						b /= i;
						arr[j] /= i;
						flag = 1;
						break;
					}

				}
			}
			if (flag == 1) break;
		}
	}
}

int main() {

	//nCm 출력
	// 5 <= n,m <= 100
	int N, M;
	std::cin >> N >> M;
	long long sum = 1;
	int big_num = (N - M > M) ? (N - M) : M;

	for (int i = 0; i < N - big_num; i++) {
		arr[i] = N - i;
	}

	for (int i = 2; i <= N - big_num; i++) {
		find_num(N - big_num, i);
	}
	int index = 0; // 자릿수
	// 
	for (int i = 0; i < N - big_num; i++) {
		for (int j = 0; j <= index; j++) {
			mul[j] *= arr[i];
		}
		int size = index;
		for (int j = 0; j <= size; j++) {
			int t = 2;
			// 최대 2번
			while (mul[j] >= 10) {
				int ten = 1;
				for (int k = 0; k < t; k++) {
					ten *= 10;
				}
				if (mul[j] / ten != 0) {
					mul[j + t] += (mul[j] / ten);
					if (index < j + t) {
						index = j + t;
					}
				}
				mul[j] = mul[j] % ten;
				t--;
			}
		}
	}
	for (int i = 0; i <= index; i++) {
		if (mul[i] >= 10) {
			mul[i + 1] += mul[i] / 10;
			if (i + 1 > index) index = i + 1;
			mul[i] %= 10;
		}
	}
	for (int i = index; i >= 0; i--) {
		std::cout << mul[i];
	}


	return 0;
}