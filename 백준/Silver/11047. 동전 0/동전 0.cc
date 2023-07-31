#include<iostream>
int coin[10];
int cnt_coin[10];
void count_coin(int total, int size) {
	cnt_coin[0] = (total / coin[0]);

	for (int i = 1; i < size; i++) {
		int mul = coin[i] / coin[i - 1]; // 몇배인지?
		cnt_coin[i] = cnt_coin[i - 1] / mul;
		if (cnt_coin[i] == 0) break;
		cnt_coin[i-1] = cnt_coin[i - 1] % mul;
	}
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += cnt_coin[i];
	}
	std::cout << sum;
}



// A_i 는 A_i-1의 배수
int main() {
	int N, K;
	std::cin >> N >> K;
	for (int i = 0; i < N; i++)	{
		std::cin >> coin[i];
	}
	count_coin(K, N);

	return 0;
}