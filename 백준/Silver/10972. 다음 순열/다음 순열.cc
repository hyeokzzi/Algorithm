#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001];
void swap(int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == N - i) cnt++;
	}
	if (cnt == N) {
		cout << "-1";
	}
	else {
		next_permutation(arr, arr + N);
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
	}

	return 0;
}