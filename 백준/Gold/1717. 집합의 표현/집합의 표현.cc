#include<iostream>
#include<cmath>
using namespace std;
int arr[1000001];
int N, M;

int find_head(int idx) {
	if (idx == arr[idx]) return idx;
	else return arr[idx] = find_head(arr[idx]);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int type, a, b;
		cin >> type >> a >> b;

		int big_idx = max(a, b);
		int small_idx = min(a, b);

		// 헤드 노드일때까지 이동
		big_idx = find_head(big_idx);
		small_idx = find_head(small_idx);
		//while (arr[big_idx] != big_idx) {
		//	big_idx = arr[big_idx];
		//}
		//while (arr[small_idx] != small_idx) {
		//	small_idx = arr[small_idx];
		//}


		if (type == 0) {
			arr[big_idx] = arr[small_idx];
		}
		else {
			if (arr[big_idx] == arr[small_idx]) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}