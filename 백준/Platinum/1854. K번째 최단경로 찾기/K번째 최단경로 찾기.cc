#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define INF 2100000000
using namespace std;
typedef pair<int, int> node;
int N, M, K;
vector<node> arr[1001]; // 도착 노드, 거리
int dist[1001];
priority_queue<int> ans[1001];

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int st, en, distance;
		cin >> st >> en >> distance;
		arr[st].push_back({ en,distance });
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	priority_queue<node, vector<node>, greater<node>> que; 
	ans[1].push(0);		// (*)처음 시작 0도 포함
	que.push({ 0, 1 });
	
	while (!que.empty()) {
		node temp = que.top();
		que.pop();

		int idx = temp.second;
		int distance = temp.first;

		for (auto& e : arr[idx]) {
			int ndist = distance + e.second;
			if (ans[e.first].size() < K) {
				ans[e.first].push(ndist);
				que.push({ ndist, e.first});
			}
			else {
				if (ans[e.first].top() > ndist) {
					ans[e.first].pop();
					ans[e.first].push(ndist);
					que.push({ ndist, e.first });
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i].size() >= K) {
			cout << ans[i].top() << '\n';
		}
		else cout << "-1" << '\n';
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