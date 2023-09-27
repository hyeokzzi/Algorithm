#include<iostream>
#include<cmath>
using namespace std;
int arr[201];
int N, M;

int find_head(int idx) {
	if (arr[idx] == idx) return idx;
	else return arr[idx] = find_head(arr[idx]);
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int t;
			cin >> t;

			if (t == 1) {
				int big_idx = max(i, j);
				int small_idx = min(i, j);

				big_idx = find_head(big_idx);
				small_idx = find_head(small_idx);

				arr[big_idx] = arr[small_idx];
			}
		}
	}
	int ans = 0;
	int flag = 0;
	for (int i = 0; i < M; i++) {
		int idx;
		cin >> idx;
		if (ans == 0) ans = find_head(idx);
		else {
			if (ans != find_head(idx)) flag++;
		}
	}

	if (flag == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}