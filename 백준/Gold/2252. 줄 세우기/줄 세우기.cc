#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N, M;
vector<int> vec[32001];
vector<int> ans;
int arr[32001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, en;
		cin >> st >> en;
		vec[st].push_back(en);
	}
}

void solution() {
	// 저장
	for (int i = 1; i <= N; i++) {
		for (auto& e : vec[i]) {
			arr[e]++;
		}
	}

	// 시작
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			que.push(i);
		}
	}

	// 정렬
	while (!que.empty()) {
		int idx = que.front();
		que.pop();
		if (arr[idx] == 0) {
			ans.push_back(idx);
			for (auto& e : vec[idx]) {
				arr[e]--;
				if (arr[e] == 0) que.push(e);
			}
		}
	}

	for (auto& e : ans) {
		cout << e << " ";
	}
}

int main() {
	input();
	solution();
	return 0;
}