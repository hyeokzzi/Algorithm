#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int value[501];			// 건물 짓는데 걸리는 시간
int arr[501];			// 위상배열
vector<int> vec[501];	// 노드 연결
int ans[501];
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t;
		int flag = 0;
		while (1) {
			cin >> t;
			if (t == -1) break;
			if (flag == 0) {
				value[i] = t;
				flag++;
			}
			else {
				vec[t].push_back(i);
				arr[i]++;		// 이 건물을 짓기위해 필요한 건물 수 저장
			}
		}
	}
}

void solution() {
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		ans[i] = value[i];
		if (arr[i] == 0) que.push(i);
	}

	while (!que.empty()) {
		int idx = que.front();
		que.pop();
		for (auto& e : vec[idx]) {
			arr[e]--;
			ans[e] = max(value[e] + ans[idx], ans[e]);
			if (arr[e] == 0) {
				que.push(e);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}