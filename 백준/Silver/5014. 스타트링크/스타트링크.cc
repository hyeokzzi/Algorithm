#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue<int> que;
int visited[1000001] = { 0 };
int F, S, G, U, D;
void bfs(int U, int D) {
	int mv[2] = { U, -D };
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front();
			que.pop();
			for (int i = 0; i < 2; i++) {
				int tx = x + mv[i];
				if (tx < 1 || tx > F) continue;
				if (visited[tx] > visited[x] + 1 || visited[tx] == 0) {
					visited[tx] = visited[x] + 1;
					que.push(tx);
				}
			}
		}
	}
}




int main() {
	// 전체, 현재, 목표, 위로 몇층, 아래 몇층
	cin >> F >> S >> G >> U >> D;

	que.push(S);
	visited[S] = 1;
	bfs(U, D);
	if (visited[G] == 0) {
		cout << "use the stairs";
	}
	else {
		cout << visited[G] - 1;
	}

	
	return 0;
}