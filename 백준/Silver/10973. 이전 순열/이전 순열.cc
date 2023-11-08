#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, arr[10001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	if (!prev_permutation(arr, arr + N)) cout << "-1";
	else {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}