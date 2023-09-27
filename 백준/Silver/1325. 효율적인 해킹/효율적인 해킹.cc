#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
vector<int> arr[10001];
vector<int> ans;
queue<int> que;
int visited[10001];
int N, M;
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, en;
		cin >> st >> en;
		arr[en].push_back(st);
	}
}


int bfs(int node) {
	bool visited[10001] = { false };
	que.push(node);
	visited[node] = true;
	int cnt = 1;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int n = que.front();
			que.pop();
			for (auto& e : arr[n]) {
				if (visited[e] == false) {
					visited[e] = true;
					que.push(e);
					cnt++; // 해킹 되는 컴퓨터 추가
				}
			}
		}
	}
	return cnt;
}

void solution() {
	int max_cnt = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = bfs(i);
		if (max_cnt <= tmp) {
			if (tmp != max_cnt) {
				ans.clear();
				max_cnt = tmp;
			}
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto& e : ans) {
		cout << e << " ";
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