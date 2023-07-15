#include<iostream>
#define INF 21000000
using namespace std;
int N, M;
char arr[501][501];

int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int PR, PC;
	cin >> PR >> PC;
	// 초기 방향
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	char ans[4] = { 'U','R','D','L' };
	int cnt_arr[4] = { 0, };

	for (int i = 0; i < 4; i++) {
		// 위치
		int x = PC;
		int y = PR;
		// 방향
		int tx = dx[i];
		int ty = dy[i];
		// 이동거리
		int cnt = 0;

		// 무한루프 - 방향저장
		int visited[501][501] = { 0, };
		int d_idx = i + 1;

		while (1) {
			// 이동
			cnt++;
			x = x + tx;
			y = y + ty;
			// 종료 조건 1 - 벗어남
			if (x < 1 || x > M || y< 1 || y > N) break;

			// 종료조건 2 -무한루프 판독 ( 이전 방문 방향과 같을 때 )
			if (visited[y][x] == d_idx) {
				cnt = INF;
				break;
			}

			// 종료조건 3 - 블랙혹
			if (arr[y][x] == 'C') break;

			// 반사
			if (arr[y][x] == '/') {
				int temp = ty;
				ty = -tx;
				tx = -temp;
				for (int j = 0; j < 4; j++) {
					if (ty == dy[j] && tx == dx[j]) {
						d_idx = j + 1;
						break;
					}
				}
			}
			else if (arr[y][x] == '\\') {
				int temp = ty;
				ty = tx;
				tx = temp;
				for (int j = 0; j < 4; j++) {
					if (ty == dy[j] && tx == dx[j]) {
						d_idx = j + 1;
						break;
					}
				}
			}
			visited[y][x] = d_idx;
		}
		cnt_arr[i] = cnt;
	}

	int max_idx = 0;
	for (int i = 1; i < 4; i++) {
		if (cnt_arr[max_idx] < cnt_arr[i]) max_idx = i;
	}
	cout << ans[max_idx] << '\n';
	if (cnt_arr[max_idx] == INF) {
		cout << "Voyager";
	}
	else {
		cout << cnt_arr[max_idx];
	}

	return 0;
}