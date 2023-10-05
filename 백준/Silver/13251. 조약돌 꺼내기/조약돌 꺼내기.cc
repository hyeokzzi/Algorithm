#include<iostream>
#include<vector>
using namespace std;
int arr[51];


int main() {
	int M, K, N = 0;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
		N += arr[i];
	}
	cin >> K;
	double total = 0;
	for (int i = 0; i < M; i++) {
		if (arr[i] < K) continue;
		double sum = 1;
		for (int j = 0; j < K; j++) {
			sum *= ((double)(arr[i] - j) / (double)(N - j));
		}
		total += sum;
	}
	cout << fixed;
	cout.precision(9);
	cout << total;

	return 0;
}