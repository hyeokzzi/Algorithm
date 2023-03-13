#include<iostream>
#include<vector>
typedef struct node {
	std::vector<int> arr;
} node; // 입력받은 정수 저장 구조체

node connect[100001]; // 입력받은 연결된 두 정점을 저장한 구조체 배열
int head[100001]; // 각 숫자의 부모노드를 저장하는 배열
void find_head(int head_num); // DFS 방식으로 각 부모노드의 숫자를 저장

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int N;
	std::cin >> N;
	for (int i = 0; i < N-1; i++) {
		int num1, num2;
		std::cin >> num1 >> num2;
		connect[num1].arr.push_back(num2);
		connect[num2].arr.push_back(num1);
	}
	find_head(1);
	for (int i = 2; i <= N; i++) {
		std::cout << head[i] << '\n';
	}
	return 0;
}

void find_head(int head_num) {
	for (auto& e : connect[head_num].arr) {
		if (head[e] == 0) {
			head[e] = head_num;
			find_head(e);
		}
	}
	return;
}