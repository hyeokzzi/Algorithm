#include<iostream>
using namespace std;
int N, M;
int arr[100001];
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
}

void solution() {
	int max_distance = 0;
	int cnt = 0;
	int light_cnt = 0;
	for (int i = 0; i <= N; i++) {
		if (arr[i] == 1) {
			if (light_cnt == 0) {
				max_distance = max(cnt, max_distance);
			}
			else {
				cnt++;
				if (cnt % 2 == 1) {
					cnt++;
				}
				max_distance = max(cnt / 2, max_distance);
			}
			light_cnt++;
			cnt = 0;
		}
		else {
			cnt++;
		}
	}
	max_distance = max(cnt, max_distance);
	cout << max_distance;
}

int main() {
	input();
	solution();
	return 0;
}