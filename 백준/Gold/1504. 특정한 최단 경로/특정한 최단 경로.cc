#include<iostream>
#include<vector>
#include<queue>

#define INF 210000000

using namespace std;

vector<pair<int, int>> arr[801];

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
	priority_queue<pair<int, int>> que1;
	priority_queue<pair<int, int>> que2;

	int distance_v1[801] = { 0, };
	int distance_v2[801] = { 0, };

	bool visited_v1[801] = { false };
	bool visited_v2[801] = { false };
	for (int i = 1; i <= N; i++) {
		distance_v1[i] = INF;
		distance_v2[i] = INF;
	}

	// v1에 대한 다익스트라
	distance_v1[v1] = 0; 
	que1.push({ 0,v1 });
	while (!que1.empty()) {
		int a = que1.top().second;
		que1.pop();
		if (visited_v1[a]) continue;
		visited_v1[a] = true;
		for (auto e : arr[a]) {
			int b = e.first, w = e.second;
			if (distance_v1[a] + w < distance_v1[b]) {
				distance_v1[b] = distance_v1[a] + w;
				que1.push({ -distance_v1[b], b });
			}
		}
	}
	
	
	// v2에 대한 다익스트라
	distance_v2[v2] = 0;
	que2.push({ 0,v2 });
	while (!que2.empty()) {
		int a = que2.top().second;
		que2.pop();
		if (visited_v2[a]) continue;
		visited_v2[a] = true;
		for (auto e : arr[a]) {
			int b = e.first, w = e.second;
			if (distance_v2[a] + w < distance_v2[b]) {
				distance_v2[b] = distance_v2[a] + w;
				que2.push({ -distance_v2[b], b });
			}
		}
	}


	int sum1 = distance_v1[1] + distance_v1[v2] + distance_v2[N]; // 0 -> v1 -> v2 -> N 
	int sum2 = distance_v2[1] + distance_v2[v1] + distance_v1[N]; // 0 -> v2 -> v1 -> N
	int ans = min(sum1, sum2);
	if (ans >= INF) {
		cout << -1;
	}
	else cout << min(sum1, sum2);



	return 0;
}