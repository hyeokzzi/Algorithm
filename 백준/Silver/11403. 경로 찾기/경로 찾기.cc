#include<iostream>
#include<vector>

//std::vector<int> arr[101];
int graph[101][101];

void check_connect(int i, int size) {

	// 플로이드 사용
	// i를 거쳐서 연결되는 것을 새롭게 추가.
	for (int k = 1; k <= size; k++) {
		if (graph[k][i] == 1) {
			for (int v = 1; v <= size; v++) {
				if (graph[i][v] == 1 && graph[k][v] == 0) {
					graph[k][v] = 1;
				}
			}
		}
	}
}


int main() {


	std::cin.tie(0);
	std::cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			int num;
			std::cin >> num;
			if (num == 1) {
				graph[i][k] = 1;
	//			arr[i].push_back(k);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		check_connect(i, N);
	}

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			std::cout << graph[i][k] << " ";
		}
		std::cout << '\n';
	}

	return 0;
}