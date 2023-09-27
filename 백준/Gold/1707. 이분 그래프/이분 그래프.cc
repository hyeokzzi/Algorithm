#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int T, V, E;
vector<int> arr[20001];
int visited[20001];
bool visit[20001];
bool checked = false;
void input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
}
void dfs(int node) {
	for (auto& e : arr[node]) {
		if (visit[e] == false) {
			visited[e] = (visited[node] + 1) % 2;
			visit[e] = true;
			dfs(e);
		}
		else {
			// 이전노드인지 확인 홀짝
			if (visited[e] == visited[node]) {
				checked = true;
				return;
			}
		}
	} 
}


void solution() {

	for (int i = 1; i <= V; i++) {
		visit[i] = true;
		dfs(i);
		if (checked == true) {
			cout << "NO" << '\n';
			break;
		}
	}
	if (checked == false) cout << "YES" << '\n';

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= V; j++) {
			arr[j].clear();
			visited[j] = 0;
			visit[j] = false;
			checked = false;
		}
		input();
		solution();

	}
	return 0;

}