#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> arr[10001];
int N, D;
int dist = 10001;

void dfs(int sum, int idx) {
	for (int i = idx; i <= D; i++) {
		if (!arr[i].empty()) {
			for (auto& e : arr[i]) {
				if (e.first > D) continue;
				dfs(sum + e.second, e.first);
			}
		}
		sum++;
	}
	if (sum < dist) {
		dist = sum;
	}
}


int main() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int st, en, dist;
		cin >> st >> en >> dist;
		arr[st].push_back({ en, dist });
	}
	dfs(0, 0);
	cout << dist - 1;



	return 0;
}

