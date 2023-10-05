#include<iostream>
using namespace std;
int N, M, K;
int k = 2;
long arr[3000001];
void input() {
	cin >> N >> M >> K;
	// k값 구하기
	while (k < N) {
		k *= 2;
	}
	// 배열 초기화 - 입력값 삽입
	int idx = k;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		arr[idx++] = num;
	}
}

void solution() {

	// 배열 초기화 - 노드합 삽입
	for (int i = k - 1; i > 0; i--) {
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}

	// 1 - 변경, 2 - 구간합
	for (int i = 0; i < M + K; i++) {
		int flag;
		cin >> flag;
		// 변경
		if (flag == 1) {
			int target_node;
			long long num;
			cin >> target_node >> num;

			int idx = target_node + k - 1;
			arr[idx] = num;
			idx /= 2;

			while (idx > 0) {
				arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
				idx /= 2;
			}
		}
		// 구간합 구하기
		else {
			int st, en;
			cin >> st >> en;
			long long sum = 0;
			st = k + st - 1;
			en = k + en - 1;
			while (st <= en) {
				// 이전 저장
				if (st % 2 == 1) sum += arr[st];
				if (en % 2 == 0) sum += arr[en];
				st = (st + 1) / 2;
				en = (en - 1) / 2;
			}
			cout << sum << '\n';
		}
	}
}

int main() {
	input();
	solution();
	return 0;
}