#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
typedef struct edge {
	int st, en, distance;
	bool operator >(const edge& temp) const {
		return distance > temp.distance;
	}
}edge;

int N, total_len = 0;
int dist[51]; 
priority_queue<edge, vector<edge>, greater<edge>> que;

void input() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= N; j++) {
			int num = 0;
			if (s[j - 1] >= 'A' && s[j - 1] <= 'Z') {
				num = s[j - 1] - 'A' + 27;
			}
			else if (s[j - 1] >= 'a' && s[j - 1] <= 'z') {
				num = s[j - 1] - 'a' + 1;
			}
			total_len += num;
			if (i == j || num == 0) continue;
			que.push({ i,j,num });
		}
	}
}

int find_head(int idx) {
	if (idx == dist[idx]) return idx;
	else return dist[idx] = find_head(dist[idx]);
}

void solution() {
	for (int i = 1; i <= N; i++) {
		dist[i] = i;
	}

	int cnt = 0;
	int sum = 0;
	while (cnt < N - 1) {
		if (que.empty()) break;
		edge temp = que.top();
		que.pop();

		int idx1 = find_head(temp.st);
		int idx2 = find_head(temp.en);

		int small_idx = min(idx1, idx2);
		int big_idx = max(idx1, idx2);

		if (small_idx != big_idx) {
			dist[big_idx] = small_idx;
			cnt++;
			sum += temp.distance;
		}
	}
	if (cnt == N - 1 && total_len >= sum) {
		cout << total_len - sum;
	}
	else {
		cout << "-1";
	}

}

int main() {
	input();
	solution();
	return 0;
}