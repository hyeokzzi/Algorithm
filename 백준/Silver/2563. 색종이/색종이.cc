#include<iostream>
using namespace std;
int arr[101][101] = { 0, };
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				arr[i][j]++;
			}
		}	
	}
	int sum = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (arr[i][j] >= 1) {
				sum++;
			}
		}
	}
	cout << sum;




	return 0;
}