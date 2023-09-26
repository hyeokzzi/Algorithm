#include<iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		int big = 0, small = 0;
		int tmp = 0;
		int ans = 0;
		if (a >= b) {
			big = a;
			small = b;
		}
		else {
			big = b;
			small = a;
		}
		tmp = big % small;
		while (tmp != 0) {
			big = small;
			small = tmp;
			tmp = big % small;
		}
		ans = small;

		cout << (a * b / ans) << '\n';


	}


	return 0;
}