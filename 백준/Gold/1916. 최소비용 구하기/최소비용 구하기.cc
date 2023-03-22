#include<iostream>
#include<queue>
#include<vector>
#define INF 1000000000
void dijkstra(int node);

std::vector < std::pair<int, int>> arr[100001];
int dist[1001];

int main() {

	int city;
	std::cin >> city;

	int bus;
	int start_node, arrive_node, time;
	std::cin >> bus;
	for (int i = 0; i < bus; i++) {
		std::cin >> start_node >> arrive_node >> time;
		arr[start_node].push_back({ arrive_node, time });
	}

	for (int i = 1; i <= city; i++) {
		dist[i] = INF;
	}

	std::cin >> start_node >> arrive_node;
	dijkstra(start_node);
	std::cout << dist[arrive_node];


	return 0;
}

void dijkstra(int start_node) {
	
	std::priority_queue<std::pair<int, int>> pq; // < 도착 노드, 거리 >
	pq.push({ start_node, 0 }); 
	dist[start_node] = 0;

	while (!pq.empty()) {
		int distance = -pq.top().second;
		int current_node = pq.top().first;
		pq.pop();

		if (dist[current_node] < distance) continue;

		for (int i = 0; i < arr[current_node].size(); i++) {
			int via_distance = distance + arr[current_node][i].second;

			if (via_distance < dist[arr[current_node][i].first]) {
				dist[arr[current_node][i].first] = via_distance;
				pq.push({arr[current_node][i].first, -via_distance });
			}
		}
	}

}