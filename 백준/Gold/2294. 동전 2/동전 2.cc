#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
int arr[101];
int ans[10001];
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	sort(arr, arr + n);
	for (int i = 1; i <= k; i++) {
		ans[i] = 1000000000;
	}
	for (int i = 0 ; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			ans[j] = min(1 + ans[j - arr[i]], ans[j]);
		}
	}
	if (ans[k] > 100000) cout << "-1";
	else cout << ans[k];
}

int main() {
	input();
	solution();

	return 0;
}