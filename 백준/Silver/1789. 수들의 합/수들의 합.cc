#include<iostream>
using namespace std;
int main() {
	long long N;
	cin >> N;

	long long idx = 1;
	long long cnt = 0;
	while (1) {
		if (N - idx < 0) break;
		else if (N - idx == 0) {
			cnt++;
			break;
		}
		N -= idx;
		idx++;
		cnt++;
	}
	cout << cnt;

	return 0;
}