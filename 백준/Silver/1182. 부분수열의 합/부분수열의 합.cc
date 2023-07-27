#include<iostream>
using namespace std;
int N, S;
int arr[20];
int cnt = 0;
void func(int level, int sum) {
	if (level == N) {
		// 합이 같은지 확인
		if (sum == S)  cnt++;
		return;
	}
	func(level + 1, sum);
	func(level + 1, sum + arr[level]);
}


int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (S == 0) cnt--;
	cout << cnt;
	return 0;
}