#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1000000000
vector<pair<int,int>> arr[20001];

int main() {
	int V, E, startNode;
	cin >> V >> E >> startNode;

	for (int i = 0; i < E; i++) {
		int sNode, eNode, distance;
		cin >> sNode >> eNode >> distance;
		arr[sNode].push_back({ eNode, distance });
	}

	priority_queue<pair<int, int>> que;
	int distance[20001] = { 0, };
	bool visited[20001] = { false };

	for (int i = 1; i <= V; i++) {
		distance[i] = INF;
	}
	distance[startNode] = 0;
	que.push({ 0,startNode });
	while (!que.empty()) {
		int current = que.top().second;
		que.pop();
		if (visited[current]) continue;
		visited[current] = true;
		
		for (auto e : arr[current]) {
			int next_node = e.first;
			int next_distance = e.second;

			if (distance[current] + next_distance < distance[next_node]) {
				distance[next_node] = distance[current] + next_distance;
				que.push({ -distance[next_node], next_node });
			}
		}
	}



	for (int i = 1; i <= V; i++) {
		if (distance[i] >= INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << distance[i] << '\n';
		}
	}
	return 0;
}