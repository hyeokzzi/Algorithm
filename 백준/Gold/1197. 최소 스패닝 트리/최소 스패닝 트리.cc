#include<iostream>
//#include<vector>
#include<queue>
//#include<tuple>
#include<cmath>
using namespace std;

// 구조체 오름차순 정렬 방법 - 정석
// const없으면 에러발생
typedef struct edge {
	int st, en, distance;
	bool operator > (const edge& temp)  const {
		return distance > temp.distance;
	}
}edge;

int V, E;
priority_queue<edge, vector<edge>, greater<edge>> que;
int dist[10001];

/*
struct compare {
	bool operator()(edge a, edge b) {
		if (get<2>(a) > get<2>(b))return true;
		else return false;
	}
};
*/
void input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int st, en, distance;
		cin >> st >> en >> distance;
		que.push({ st,en,distance });
	}
}

int find_idx(int idx) {
	if (dist[idx] == idx) return idx;
	else return dist[idx] = find_idx(dist[idx]);
}


// 1. 유니온 배열 -> 2. 오름차순 정렬 -> 3. 거리 작은 순서대로 연결
void solution() {
	for (int i = 1; i <= V; i++) {
		dist[i] = i;
	}
	int sum = 0;
	while (!que.empty()) {
		edge temp = que.top();
		que.pop();

		int idx1 = find_idx(temp.st);
		int idx2 = find_idx(temp.en);

		int small_idx = min(idx1, idx2);
		int big_idx = max(idx1, idx2);
		// 사이클 확인
		if (small_idx != big_idx) {
			dist[big_idx] = small_idx;
			sum += temp.distance;
		}
	}
	cout << sum;

}

int main() {
	input();
	solution();
	return 0;
}