#include<iostream>
#include<math.h>

int arr[10];
int check_possible(int num, int M);
int find_num(int channel, int M);
int main() {

	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int N,M;
	std::cin >> N >> M;
	if (M == 10) {
		std::cout << abs(N - 100);
		return 0;
	}
	for (int i = 0; i < M; i++) {
		std::cin >> arr[i];
	}
	
	int t = find_num(N, M);
	int sum1 = abs(N - 100);
	int sum2 = abs(t - N);
	do {
		sum2++;
		t /= 10;
	} while (t != 0);

	if (sum1 > sum2) {
		std::cout << sum2;
	}
	else {
		std::cout << sum1;
	}

	return 0;
}


int check_possible(int num, int M) {
	
	do {
		int t = num % 10;
		for (int i = 0; i < M; i++) {
			if (arr[i] == t) return -1;
		}
		num /= 10;
	} while (num != 0);
	return 0;
}

int find_num(int channel, int M) {
	if (check_possible(channel, M) == 0) return channel;

	int minus = channel - 1;
	int plus = channel + 1;

	while (1) {
		if (minus >= 0 && check_possible(minus, M) == 0){
			return minus;
		}
			
		if (check_possible(plus, M) == 0) {
			return plus;
		}
		minus--;
		plus++;
	}
}