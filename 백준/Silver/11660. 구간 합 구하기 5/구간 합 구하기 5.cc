#include<iostream>

typedef struct node {
	int num;
	int stack;
}node;
node arr[1025][1025];
int mul_sum(int x1, int y1, int x2, int y2);

int main() {

	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int N, M;
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			std::cin >> arr[i][j].num;
			sum += arr[i][j].num;
			arr[i][j].stack = sum;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		std::cout << mul_sum(x1, y1, x2, y2) << '\n';
	}
	return 0;
}

int mul_sum(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = x1; i <= x2; i++) {
		sum += arr[i][y2].stack - arr[i][y1-1].stack;
	}
	return sum;
}