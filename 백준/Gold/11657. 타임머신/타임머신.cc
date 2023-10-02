#include<iostream>
#include<vector>
#include<tuple>
#define INF 9223372036854775806
using namespace std;
long long dist[501];
int save[501];
int N, M;
typedef tuple<int, int, int> edge;
vector<edge> vec;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, en, cost;
		cin >> st >> en >> cost;
		vec.push_back({ st,en,cost });
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;

	// N번하면 음수사이클 측정
	for (int i = 0; i < N - 1; i++) {
		// 엣지 갯수만큼
		for (auto& e : vec) {
			int st = get<0>(e);
			int en = get<1>(e);
			int cost = get<2>(e);

			if (dist[st] != INF && dist[en] > dist[st] + cost) {
				dist[en] = dist[st] + cost;
			}
		}
	}

	// 사이클 확인
	int flag = 0;
	for (auto& e : vec) {
		int st = get<0>(e);
		int en = get<1>(e);
		int cost = get<2>(e);

		if (dist[st] != INF && dist[en] > dist[st] + cost) {
			flag = 1;
		}
	}

	if (flag == 0) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << "-1" << '\n';
			else cout << dist[i] << '\n';
		}
	}
	else cout << "-1" << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}