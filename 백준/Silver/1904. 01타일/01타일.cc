#include<iostream>
using namespace std;
int arr[1000001];
int main() {
	int N;
	cin >> N;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	cout << arr[N];
	return 0;
}