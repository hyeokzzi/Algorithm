#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, C;
vector<int> arr;
void input() {
	cin >> N >> C;
	for (int i = 0; i < N; i ++ ) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
}

void solution() {
	int start_dist = 1;
	int end_dist = 1000000001;
	int cur_dist = (start_dist + end_dist) / 2;
	int max_dist = 0;
	int flag = 0;
	while (1) {
		int cnt = 1, idx = 1, sum = 0;
		if (flag == 1) break;
		if (start_dist + 1 == end_dist) flag++;
		while (1) {
			if (idx == N) break;
			sum += (arr[idx] - arr[idx - 1]);
			if (sum >= cur_dist) {
				cnt++;
				sum = 0;
			}
			idx++;
		}

		// 거리 조절 판단
		if (cnt >= C) {
			max_dist = max(max_dist, cur_dist);
			start_dist = cur_dist;
			cur_dist = (start_dist + end_dist) / 2;
		}
		else {
			end_dist = cur_dist;
			cur_dist = (start_dist + end_dist) / 2;
		}
	}
	cout << max_dist;
}

int main() {

	input();
	solution();

	return 0;
}