#include<iostream>
using namespace std;
int dp(int N) {
	if (N % 2 == 1) return 0;
	if (N >= 4) {
		int sum = 2;
		for (int i = N; i >= 4; i -= 2) {
			sum += 2 * dp(i - 4);
		}
		sum += 3 * dp(N - 2);
		return sum;
	}
	if (N == 2) return 3;
	if (N == 0) return 0;
	
}

int main() {
	int N;
	cin >> N;
	cout << dp(N);
	return 0;
}