#include<iostream>
#include<vector>
#include<queue>

#define INF 210000000
using namespace std;
vector<pair<int, int>> arr[801];

void dijkstra(int*distance, int node, int N) {
	priority_queue<pair<int, int>> que;
	bool visited[801] = { false };
	for (int i = 1; i <= N; i++) distance[i] = INF;
	distance[node] = 0;
	que.push({ 0,node });
	while (!que.empty()) {
		int current_node = que.top().second;
		que.pop();
		if (visited[current_node]) continue;
		visited[current_node] = true;
		for (auto e : arr[current_node]) {
			int next_node = e.first;
			int next_distance = e.second;
			if (distance[current_node] + next_distance < distance[next_node]) {
				distance[next_node] = distance[current_node] + next_distance;
				que.push({ -distance[next_node], next_node });
			}
		}
	}
}

int main() {
	int N, E;
	cin >> N >> E;
	// 간선 
	for (int i = 0; i < E; i++) {
		int node1, node2, distance;
		cin >> node1 >> node2 >> distance;
		arr[node1].push_back(make_pair(node2, distance));
		arr[node2].push_back(make_pair(node1, distance));
	}

	// 반드시 거쳐야 하는 정점
	int v1, v2;
	cin >> v1 >> v2;
	
	// 두 정점에 대해 각각 다익스트라 수행
	int sum1 = 0, sum2 = 0;
	int distance[801] = { 0, };
	dijkstra(distance, v1, N);
	sum1 += distance[1] + distance[v2];
	sum2 += distance[N];

	dijkstra(distance, v2, N);
	sum1 += distance[N];
	sum2 += distance[1] + distance[v1];

	int sum = min(sum1, sum2);
	if (sum >= INF) {
		cout << -1;
	}
	else {
		cout << sum;
	}
	return 0;
}