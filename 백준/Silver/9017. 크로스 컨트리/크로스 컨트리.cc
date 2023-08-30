#include<iostream>
#include<vector>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		// 6개 팀 확인
		vector<int> arr;
		int visited[201] = { 0, };
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			arr.push_back(num);
			visited[num]++;
		}
		// 점수순으로 저장
		vector<int> score[201];
		int cnt = 1;
		for (auto& e : arr) {
			if (visited[e] >= 6) {
				score[e].push_back(cnt);
				cnt++;
			}
		}

		// 팀별로 저장?
		int min_sum = 2100000000;
		int min_idx = 0;
		for (int j = 1; j <= 200; j++) {
			if (score[j].size() < 6) continue;
			int sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += score[j][k];
			}
			if (min_idx == 0) {
				min_idx = j;
				min_sum = sum;
				continue;
			}
			if (sum < min_sum) {
				min_sum = sum;
				min_idx = j;
			}
			else if (sum == min_sum) {
				if (score[min_idx][4] > score[j][4]) {
					min_sum = sum;
					min_idx = j;
				}
			}
		}

		cout << min_idx <<'\n';

	}

	return 0;
}