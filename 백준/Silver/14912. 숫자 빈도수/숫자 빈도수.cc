#include<iostream>
using namespace std;
int main() {
	int N, num;
	cin >> N >> num;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int now = i;
		while (now != 0) {
			if (now % 10 == num) cnt++;
			now /= 10;
		}
	}
	cout << cnt;
	return 0;
}