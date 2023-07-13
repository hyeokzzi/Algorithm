#include<iostream>
#include<queue>
using namespace std;
int N, M;
int arr[101];
int visited[101] = { 0, };
int jump[101];
queue<int> que;
void bfs() {
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front();
			que.pop();
			for (int j = 1; j <= 6; j++) {
				int tx = x + j;
				if (tx < 1 || tx > 100) continue;
				// 뱀과 사다리 존재
				if (jump[tx] != 0) {
					tx = jump[tx];
					if (visited[tx] > visited[x] + 1 || visited[tx] == 0) {
						visited[tx] = visited[x] + 1;
						que.push(tx);
					}
				}
				else {
					if (visited[tx] > visited[x] + 1 || visited[tx] == 0) {
						visited[tx] = visited[x] + 1;
						que.push(tx);
					}
				}
			}
		}
	}
}


int main() {
	int cnt = 1;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		jump[num1] = num2;
	}
	que.push(1);
	visited[1] = 1;
	bfs();
	cout << visited[100] - 1;

	return 0;
}