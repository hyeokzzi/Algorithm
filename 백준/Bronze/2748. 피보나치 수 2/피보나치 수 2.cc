#include<iostream>

long long arr[91] = { 0,1, }; // 나머지 0으로 채워짐

long long dp(long long N) {
	if (N == 1 || N == 0 || arr[N] != 0) return arr[N];
	return arr[N] = dp(N - 1) + dp(N - 2);
}


int main() {

	long long N;
	std::cin >> N;
	std::cout << dp(N);

	return 0;
}