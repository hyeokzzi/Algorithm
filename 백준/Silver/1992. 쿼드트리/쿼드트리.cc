#include<iostream>
int arr[65][65];

void find_section(int start_x, int start_y, int size) {
	int check_num = arr[start_y][start_x];
	int flag = 0;
	if (size > 1) {
		for (int i = start_y; i < start_y + size; i++) {
			for (int j = start_x; j < start_x + size; j++) {
				if (arr[i][j] != check_num) {
					flag++;
					break;
				}
			}
			if (flag != 0) break;
		}
	}
	// 나누어져야할 때
	if (flag != 0) {
		std::cout << "(";
		find_section(start_x, start_y, size / 2);
		find_section(start_x + size / 2, start_y, size / 2);
		find_section(start_x, start_y + size / 2, size / 2);
		find_section(start_x + size / 2, start_y + size / 2, size / 2);
		std::cout << ")";
	}
	else {
		std::cout << check_num;
	}



}

int main() {

	int N;
	std::cin >> N;
	
	for (int i = 1; i <= N; i++) {
		
		char num[65];
		std::cin >> num;
		for (int k = 0; k < N; k++) {
			arr[i][k + 1] = num[k] - '0';
		}
	}
	find_section(1, 1, N);
	return 0;
}