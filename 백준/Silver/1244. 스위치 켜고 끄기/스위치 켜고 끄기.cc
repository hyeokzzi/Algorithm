#include<iostream>
using namespace std;
int N, M;
int arr[105];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> M;
}

void solution() {
	int gender;
	int num;
	for (int i = 0; i < M; i++) {
		cin >> gender >> num;
	
		if (gender == 1) {
			for (int i = num; i <= N; i += num) {
				if (arr[i] == 0) arr[i] = 1;
				else arr[i] = 0;
			}
		}
		else {
			// 대칭 확인
			int left = num - 1;
			int right = num + 1;
			while (1) {
				if (left < 1 || right > N) break;
				if (arr[left] != arr[right]) {
					break;
				}
				left--;
				right++;
			}
			// 결과
			for (int i = left + 1; i < right; i++) {
				if (arr[i] == 0) arr[i] = 1;
				else arr[i] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << '\n';
	}
}

int main() {

	input();
	solution();

	return 0;
}