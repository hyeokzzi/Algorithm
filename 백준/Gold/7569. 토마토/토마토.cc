#include<iostream>
#include<queue>
int arr[101][101][101];

struct node {
	int x;
	int y;
	int z;
};
std::queue<node> que;

int level = 0;

void bfs(int H, int M, int N) {
	// 이번 단계에 할 정점들 
	std::queue<node> save;


	while(que.empty() != true) {
		node a;
		a.x = que.front().x;
		a.y = que.front().y;
		a.z = que.front().z;
		save.push(a);
		que.pop();
	}
	// queue_index를 통해서 다음 단계에 갈 정점들을 find
	while(save.empty()!=true){

		int tx[6] = { 1, -1, 0, 0, 0, 0 };
		int ty[6] = { 0, 0, 1, -1, 0, 0 };
		int tz[6] = { 0, 0, 0, 0, 1, -1 };
		for (int k = 0; k < 6; k++) {
			int nx = save.front().x + tx[k];
			int ny = save.front().y + ty[k];
			int nz = save.front().z + tz[k];
			if ((nx > 0 && nx <= M) && (ny > 0 && ny <= N) && (nz > 0 && nz <= H) && arr[nz][ny][nx] == 0) {
				node a;
				a.x = nx;
				a.y = ny;
				a.z = nz;
				que.push(a);
				arr[nz][ny][nx] = 1;
			}
		}
		save.pop();
	}

	if (que.empty() != true) {
		level++;
		bfs(H, M, N);
	}
}



int main() {

	std::cin.tie(0);
	std::cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int M, N, H;
	std::cin >> M >> N >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				std::cin >> arr[i][j][k];
			}
		}
	}
	// 시작 익은 토마토 위치 queue에 저장
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (arr[i][j][k] == 1) {
					node a;
					a.x = k;
					a.y = j;
					a.z = i;
					que.push(a);
				}
			}
		}
	}

	bfs(H, M, N);

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (arr[i][j][k] == 0) {
					std::cout << "-1";
					return 0;
				}
			}
		}
	}
	if (level == 0) {
		std::cout << "0";
	}
	else {
		std::cout << level;
	}

	return 0;
}