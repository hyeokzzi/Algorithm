#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
int M, N, K;
int arr[101][101] = { 0, };
bool visited[101][101] = { false };
int dx[4] = { 0, 1, 0 ,-1 };
int dy[4] = { -1, 0 , 1, 0 };
int area = 0;
void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (ty < 0 || ty >= M || tx < 0 || tx >= N) continue;
		if (arr[ty][tx] == 0 && visited[ty][tx] == false) {
			area++;
			dfs(ty, tx);
		}
	}
}



int main() {
	// y, x, 사각형 갯수
	cin >> M >> N >> K;
	for (int k = 0; k < K; k++) {
		int y1, x1, y2, x2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	// 빈칸 확인 후 영역 넓이 계산
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && visited[i][j] == false) {
				area = 1;
				dfs(i, j);
				ans.push_back(area);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& e : ans) {
		cout << e << " ";
	}

	return 0;
}