#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int N, x, y, M;
vector<int> arr[101];
queue<int> que;
int visited[101] = { 0, };


void bfs() {

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int tx = que.front();
			que.pop();
			for (auto e : arr[tx]) {
				if (visited[e] != 0) continue;
				que.push(e);
				visited[e] = visited[tx] + 1;
				if (e == y) return;
			}
		}
	}
}

int main() {

	cin >> N >> x >> y >> M;
	for (int i = 0; i < M; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		arr[num1].push_back(num2);
		arr[num2].push_back(num1);
	}
	// x와 y중 누가 부모 노드인가?
	que.push(x);
	visited[x] = 1;
	bfs();


	if (visited[y] != 0) {
		cout << visited[y] - 1;
	}
	else {
		cout << -1;
	}
	return 0;
}
