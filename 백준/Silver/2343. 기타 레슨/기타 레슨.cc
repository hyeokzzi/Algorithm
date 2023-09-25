#include<iostream>
using namespace std;
int arr[100001];
int N, M;
int sum = 0;
int max_num = 0;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max_num = max(max_num, arr[i]);
		sum += arr[i];
	}
}

void solution() {
	int en = sum;
	int st = max_num;
	int mid = (st + en) / 2;
	int flag = 0;
	while (st <= en) {
		// 처리
		int temp = 0;
		int t = 0;		// 블루레이 수
		for (int i = 0; i < N; i++) {
			if (temp + arr[i] >= mid) {
				if (temp + arr[i] == mid) {
					temp = 0;
				}
				else {
					temp = arr[i];
				}
				t++;
			}
			else {
				temp += arr[i];
			}
		}
		if (temp != 0) t++;

		// 중앙 이동
		if (t <= M) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
		mid = (st + en) / 2;
	}
	cout << st;
}

int main() {
	input();
	solution();

	return 0;
}