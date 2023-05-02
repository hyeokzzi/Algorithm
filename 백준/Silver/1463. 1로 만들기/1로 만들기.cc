#include<iostream>
int min_count = 99999999;
void dp(int N, int count) {
	if (count > min_count) return;
	if (N == 1) {
		if (min_count > count) {
			min_count = count;
		}
		return;
	}
	if (N % 3 == 0) dp(N / 3, count + 1);
	if (N % 2 == 0) dp(N / 2, count + 1);
	dp(N - 1, count + 1);
	return;
}

int main() {
	int N;
	std::cin >> N;
	dp(N, 0);
	std::cout << min_count;

	return 0;
}