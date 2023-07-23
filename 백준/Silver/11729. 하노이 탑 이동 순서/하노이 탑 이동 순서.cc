#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N;

void input() {
	cin >> N;
}


void hanoi(int start, int mid, int target, int n) {
	if (n == 1) {
		cout << start << " " << target << '\n';
	}
	else {
		hanoi(start, target, mid, n - 1);
		cout << start << " " << target << '\n';
		hanoi(mid, start, target, n - 1);
	}
}

void solve(){
	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(1, 2, 3, N);
}

int main() {
	input();
	solve();

	return 0;
}