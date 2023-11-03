#include<iostream>
using namespace std;
long long func(long long num, int size) {
	long long cnt = 0;
	for (long long i = num; i <= size; i *= num) {
		cnt += (size / i);
	}
	return cnt;
}


int main() {
	int n, m;
	cin >> n >> m;

	long long max_num = max(n - m, m);
	long long min_num = min(n - m, m);

	long long cnt_2 = func(2, n);
	long long cnt_5 = func(5, n);

	cnt_2 -= func(2, max_num);
	cnt_2 -= func(2, min_num);
	cnt_5 -= func(5, max_num);
	cnt_5 -= func(5, min_num);

	cout << min(cnt_2, cnt_5);
	return 0;
}