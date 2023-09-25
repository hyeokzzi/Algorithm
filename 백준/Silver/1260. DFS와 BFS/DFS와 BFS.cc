#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, V;
vector<int> arr[1001];
bool visited[1001] = { false };
bool visited_q[1001] = { false };
queue<int> que;
void input() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
}


void dfs(int idx) {
	cout << idx << " ";
	for (auto& e : arr[idx]) {
		if (visited[e] == false) {
			visited[e] = true;
			dfs(e);
		}
	}
}

void bfs() {
	while (!que.empty()) {
		int idx = que.front();
		cout << idx << " ";
		que.pop();
		for (auto& e : arr[idx]) {
			if (visited_q[e] == false) {
				visited_q[e] = true;
				que.push(e);
			}
		}
	}


}

void solution() {
	for (int i = 1; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	visited[V] = true;
	dfs(V);
	cout << '\n';
	visited_q[V] = true;
	que.push(V);
	bfs();

}

int main() {
	input();
	solution();

	return 0;
}