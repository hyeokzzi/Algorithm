#include<iostream>
int save[8];
void print(int N, int M, int idx, int num) {
	if (M > 1) {
		for (int i = num; i <= N; i++) {
			save[idx] = i;
			print(N, M - 1, idx + 1, i);
		}
	}
	else {
		save[idx] = num;
		for (int i = num; i <= N; i++) {
			save[idx] = i;
			for (int k = 0; k <= idx; k++) {
				std::cout << save[k] << " ";
			}
			std::cout << "\n";
		}
	}




}


int main() {
	int N, M;
	std::cin >> N >> M;

	print(N, M, 0, 1);


	return 0;
}