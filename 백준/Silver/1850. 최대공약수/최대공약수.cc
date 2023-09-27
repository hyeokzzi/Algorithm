#include<iostream>
using namespace std;
int main() {
	long long a, b;
	cin >> a >> b;

	long long big = b, small = a;
	if (a >= b) {
		big = a;
		small = b;
	}

	long long tmp = big % small;
	long long ans = 0;
	while (tmp != 0) {
		big = small;
		small = tmp;
		tmp = big % small;
	}
	ans = small;

	for (int i = 0; i < ans; i++) {
		cout << '1';
	}
	return 0;
}