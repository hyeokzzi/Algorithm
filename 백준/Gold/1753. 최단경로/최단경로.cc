#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
#define INF 2100000000
int dist[20001];
vector<pair<int, int>> arr[20001];
bool visited[20001] = { false };
int V, E, K;

void input() {
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int st, en, distance;
		cin >> st >> en >> distance;
		arr[st].push_back({ en, distance });
	}
}

void solution() {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[K] = 0;
	que.push({ 0,K });
	while (!que.empty()) {
		int idx = que.top().second;
		int distance = que.top().first;
		que.pop();

		if (visited[idx]) continue;
		visited[idx] = true;

		for (auto& e : arr[idx]) {
			int temp = dist[e.first];
			dist[e.first] = min(dist[e.first], dist[idx] + e.second);
			if (temp != dist[e.first]) que.push({ dist[e.first], e.first });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

int main() {
	input();
	solution();
	return 0;
}