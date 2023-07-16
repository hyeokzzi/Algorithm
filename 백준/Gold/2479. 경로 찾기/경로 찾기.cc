#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int N, K;
int sNode, eNode;

queue<int> que;
int visited[1002] = { 0, };
string s[1002];
string ans[1002];

void bfs() {
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int idx = que.front();
			que.pop();

			for (int j = 1; j <= N; j++) {
				if (visited[j]) continue;
				int cnt = 0;
				// 거리가 1인지 확인
				for (int k = 0; k < K; k++) {
					if (cnt > 1) break;
					if (s[idx][k] != s[j][k]) cnt++;
				}
				// 다음 진행
				if (cnt == 1) {
					visited[j] = 1;
					que.push(j);
					ans[j] = (ans[idx] + to_string(j) + " ");
					if (j == eNode) return;
				}
			}
		}
	}
}


int main() {
	//
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> s[i];
	}
	cin >> sNode >> eNode;

	que.push(sNode);
	ans[sNode] = to_string(sNode) + " ";
	visited[sNode] = 1;
	bfs();

	int len = ans[eNode].length();
	if (len == 0) {
		cout << -1;
	}
	else {
		cout << ans[eNode];
	}
	return 0;
}