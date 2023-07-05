#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> arr[10001];

int max_diameter = 0;

int dfs(int n) {
	priority_queue<int, vector<int>, less<int>> pq;
	int size = arr[n].size();
	if (size == 0) return 0;		// 말단 노드일때 반환
	for (int i = 0; i < size; i++) {
		int len = arr[n][i].second;
		int node_len = dfs(arr[n][i].first);		// i노드의 최댓값 반환받음
		pq.push(len + node_len);
	}
	int max_len = pq.top();
	if (pq.size() >= 2) {
		pq.pop();
		max_diameter = max(max_diameter, pq.top() + max_len);
	}

	return max_len;
}


int main() {

	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int sNode, eNode, dist;
		cin >> sNode >> eNode >> dist;
		arr[sNode].push_back({ eNode, dist });
	}
	//dfs(1);
	cout << max(max_diameter, dfs(1));


	return 0;
}