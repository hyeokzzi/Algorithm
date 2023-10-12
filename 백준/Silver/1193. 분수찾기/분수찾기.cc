#include<iostream>
using namespace std;
int arr[5000][5000];
int main() {
	int N;
	cin >> N;
	int sum = 1;
	int idx = 1;
	while (1) {
		if (sum + idx > N) break; 
		sum += idx;
		idx++;
	}

	if (idx % 2 == 0) {
		int t = N - sum;
		int x = idx;
		int y = 1;
		for (int i = 0; i < t; i++) {
			x--;
			y++;
		}
		cout << y << '/' << x;
	}
	else {
		int t = N - sum;
		int x = 1;
		int y = idx;
		for (int i = 0; i < t; i++) {
			x++;
			y--;
		}
		cout << y << '/' << x;
	}

	return 0;
}