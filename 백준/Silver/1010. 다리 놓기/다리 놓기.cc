#include<iostream>
int arr[30][30] = { 0, };
int dp_combination(int x, int y) {
	
	if (x == y || x == 0) return 1;
	else if (arr[x][y] != 0) return arr[x][y];
	else {
		return arr[x][y] = dp_combination(x - 1, y - 1) + dp_combination(x, y - 1);
	}
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M;
		int arr[30] = { 1,0 };
		std::cin >> N >> M;
		std::cout << dp_combination(N, M) << '\n';
	}
	return 0;
}