#include<iostream>
// BFS 활용,,,
// Floyd 활용,,,  --> 연결된 것들의 거리를 1로 두고 하면 가능.

/*

1 1 0 1 1
1 1 1 0 0
0 1 1 0 0
1 0 0 1 1
1 0 0 1 1  ==> 여기서 0인것들을 채워 나가는 것 == 즉, 베이컨의 갯수는 거리임.

*/
int arr[101][101];
void floyd(int node_num, int size) {
	for (int i = 1; i <= size; i++) {
		for (int k = 1; k <= size; k++) {
			if (i == k) continue;
			// node_num의 정점과 둘다 연결 되어 있는 것들 중
			if (arr[i][node_num] != 0 && arr[k][node_num] != 0) {
				// 둘다 연결되어 있지 않은 경우 => 새로 연결 시켜주어야함. node_num의 정점을 통해
				if (arr[i][k] == 0) {
					arr[i][k] = arr[i][node_num] + arr[k][node_num];
				}
				// 연결되어있는 경우 => 더 짧은 것인지 확인해야함.
				else {
					if (arr[i][k] > (arr[i][node_num] + arr[k][node_num])) {
						arr[i][k] = arr[i][node_num] + arr[k][node_num];
					}
				}
			}
		}
	}


}



int main() {
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		std::cin >> A >> B;

		arr[A][B] = 1;
		arr[B][A] = 1;
	}

	// 중간노드로 설정하는 정점의 번호를 인자로 하는 floyd 함수 사용
	for (int i = 1; i <= N; i++) {
		//find_bacon(i, N);
		floyd(i, N);
	}


	//for (int i = 1; i <= N; i++) {
	//	for (int k = 1; k <= N; k++) {
	//		std::cout << arr[i][k] << " ";
	//	}
	//	std::cout << '\n';
	//}

	int smallest_bacon = 999999;
	int smallest_idx = -1;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int k = 1; k <= N; k++) {
			sum += arr[i][k];
		}
		if (smallest_bacon > sum) {
			smallest_idx = i;
			smallest_bacon = sum;
		}
	}
	std::cout << smallest_idx;

	return 0;
}