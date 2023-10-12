#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[20000] = { 0, };
	for (int i = 1; i <= 20000; i++) {
		arr[i] = i;
	}

	for (int i = 1; i <= 10000; i++) {
		int num = i;
		int sum = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		arr[sum] = 0;
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] != 0) cout << i << '\n';
	}
	return 0;
}