#include<iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int arr[10001] = { 0, }; // 지목배열 생성 arr[j] = n -> i가 n을 지목
		// 입력
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			arr[j] = num;
		}

		// 처리
		int cnt = 0;
		int target_num = 1;
		while (target_num != N) {
			if (cnt > N) break;
			target_num = arr[target_num];
			cnt++;
		}
		if (cnt > N) cout << 0 << '\n';
		else cout << cnt << '\n';
	}
}