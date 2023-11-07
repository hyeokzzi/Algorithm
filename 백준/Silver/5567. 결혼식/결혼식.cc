#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
vector<int> arr[501];
bool visited[501];
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
}


void solution(){
	queue<int> que;
	que.push(1);
	int cnt = 0;
	int sum = 0;
	visited[1] = true;
	while (!que.empty()) {
		int size = que.size();
		if (cnt == 2) break;
		for (int i = 0; i < size; i++) {
			int idx = que.front();
			que.pop();
			for (auto& e : arr[idx]) {
				if (visited[e]) continue;
				visited[e] = true;
				que.push(e);
				sum++;
			}
		}
		cnt++;
	}
	cout << sum;


}

int main() {
	input();
	solution();

	return 0;
}