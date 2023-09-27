#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K, X;
vector<int> arr[300001];
queue<int> que;
vector<int> ans;
int visited[300001];
void input() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
	}
}

void solution() {
	que.push(X);
	visited[X] = 1;

	int distance = 1;
	int cnt = 0;
	while (!que.empty() && distance <= K) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int snode = que.front();
			que.pop();
			for (auto& e : arr[snode]) {
				if (visited[e] == 0) {
					que.push(e);
					visited[e] = 1;
				}
			}
		}
		distance++;
	}
	if (que.empty()) cout << "-1";
	else {
		while (!que.empty()) {
			ans.push_back(que.front());
			que.pop();
		}
		sort(ans.begin(), ans.end());
		for (auto& e : ans) {
			cout << e << '\n';
		}
	}
}

int main() {
	input();
	solution();

	return 0;
}