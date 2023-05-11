#include<iostream>
using namespace std;
int main() {
	int N;
	while (cin >> N) {
		int n = N;
		int num = 1;
		int cnt = 1;
		while (1) {
			if (num % n == 0) break;
			num = num * 10 + 1;
			num %= n;
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}