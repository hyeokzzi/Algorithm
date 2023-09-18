#include<iostream>
#include<vector>
using namespace std;
// 방향 - 최소값을 저장한 방향
// 1 2 3
int visited[6][6];
int arr[6][6];
int N, M;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}
int min_sum = 21000000;
int dx[3] = { -1,0,1 };
void dfs(int y, int x) {
	if (y == N - 1) {
		min_sum = min(min_sum, arr[y][x]);
		return;
	}
	for (int i = 0; i < 3; i++) {
		int tx = dx[i] + x;

		// 나한테 왔던 방향과 같은 경우 제외
		if (visited[y][x] == i + 1) continue;
		// 범위 이탈제외
		if (tx < 0 || tx >= M) continue;

		visited[y + 1][tx] = i + 1;
		arr[y + 1][tx] += arr[y][x];
		dfs(y + 1, tx);
		visited[y + 1][tx] = 0;
		arr[y + 1][tx] -= arr[y][x];
	}

}

void solution() {

	for (int i = 0; i < M; i++) {
		dfs(0, i);
	}
	cout << min_sum;
}


int main() {
	input();
	solution();
	return 0;
}