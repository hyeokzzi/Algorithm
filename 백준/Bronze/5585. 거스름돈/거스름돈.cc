#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	N = 1000 - N;
	int coin[] = { 500,100,50,10,5,1 };
	int cnt = 0;
	int idx = 0;
	while (N != 0) {
		if (N >= coin[idx]) {
			cnt += (N / coin[idx]);
			N = N % coin[idx];
		}
		idx++;
	}
	cout << cnt;
	return 0;
}