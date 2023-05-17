#include<iostream>
using namespace std;
int coin[100];
int arr[10001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	arr[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < coin[i])continue;
			arr[j] += arr[j - coin[i]];
		}
	}
	cout << arr[k];
	return 0;
}