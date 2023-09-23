#include<iostream>
// DFS 문제
// 깊이 우선 탐색

// 한 점을 통해 연결된 모든 것을 지움
int arr[1001][1001];
int connect_component = 0;
int check_arr[1001];
void find_component(int index, int size) {

	int flag = 0;
	for (int i = 1; i <= size; i++) {
		if (index != i && arr[index][i] == 1) {
			arr[index][i] = 0;
			arr[i][index] = 0;

			check_arr[i] = 1;

			find_component(i, size);
			flag++;
		}
	}
	return;

}


int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int start_node;
		int end_node;
		std::cin >> start_node >> end_node;
		// 연결 표시
		arr[start_node][end_node] = 1;
		arr[end_node][start_node] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (check_arr[i] != 1) {
			find_component(i, N);
			cnt++;
		}
	}
	
	std::cout << cnt;
		

	return 0;
}