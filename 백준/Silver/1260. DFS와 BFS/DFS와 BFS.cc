#include<iostream>
#include<queue>

// 수행시간 2초 

int bfs_arr[1001][1001]; // 연결된 간선 확인  // 연결시 = 1 / 연결x = 0
int dfs_arr[1001][1001];
// 형식 bfs_arr[정점 번호1][정점 번호2] = 1  : 정점 번호 1과 2가 연결되어있음.
int queue[1001];
int stack[1001];
int print_stack[1001];
int index_queue = 0;
int index_stack = 0;
int print_index = 0;

// DFS 재귀함수 사용,,?
// 노드 도착 -> 노드 번호 스택에 입력 -> 연결된 노드 찾아 이동
void DFS(int node_max, int num){
	// 도착한 노드 출력 목록에 저장.
	print_stack[print_index] = num;
	print_index++;
	
	for (int i = 0; i <= node_max; i++) {
		// 더이상 찾을 노드가 없을 경우 break로 모두 탈출
		// 시간 절약?
		if (print_index == node_max) return;
		if (dfs_arr[num][i] == 1) {
			int flag = 0;
			for (int k = 0; k < print_index; k++) {
				if (print_stack[k] == i) {
					flag = 1;
					break;
				}
			}
			if (flag != 0) continue;
			dfs_arr[num][i] = 0;
			dfs_arr[i][num] = 0;
			DFS(node_max, i);

		}
	}

}

void BFS(int node_max, int index) {
	for (int i = 1; i <= node_max; i++)
	{
		if (i == queue[index]) continue;
		if (bfs_arr[queue[index]][i] == 1) {
			
			int flag = 0;
			for (int k = 0; k <=index_queue; k++) {
				if (queue[k] == i) {
					flag = 1;
					break;
				}
			}
			if (flag != 0) continue;

			index_queue++;
			queue[index_queue] = i;

			bfs_arr[queue[index]][i] = 0;
			bfs_arr[i][queue[index]] = 0;
		}
	}
	if (queue[index + 1] != 0) {
		BFS(node_max, index + 1);
	}
}



int main()
{
	int N, M, V; // N : 정점의 개수 / M : 간선의 개수 / V : 시작 노드

	std::cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		std::cin >> node1 >> node2;
		bfs_arr[node1][node2] = 1;
		bfs_arr[node2][node1] = 1;

		dfs_arr[node1][node2] = 1;
		dfs_arr[node2][node1] = 1;

	}
	queue[0] = V;

	DFS(N, V);
	BFS(N, 0);
	for (int i = 0; i < N; i++) {
		if (print_stack[i] != 0) {
			std::cout << print_stack[i] << " ";
		}
	}
	std::cout << '\n';

	for (int i = 0; i < N; i++) {
		if (queue[i] != 0) {
			std::cout << queue[i] << " ";
		}
	}

	return 0;
}