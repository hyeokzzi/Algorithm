#include<iostream>

int find_long_arr(int *arr, int index, int size);
int result_arr[1000];
int main() {
	
	int A_size;
	std::cin >> A_size;
	int A_arr[1000] = { 0, };
	for (int i = 0; i < A_size; i++) {
		std::cin >> A_arr[i];
	}
	int max = 0;
	for (int i = 0; i < A_size; i++) {
		int t = find_long_arr(A_arr, i, A_size);
		if (max < t) {
			max = t;
		}
	}
	std::cout << max;

	return 0;
}

int find_long_arr(int* arr, int index, int size) {
	if (result_arr[index] == 0) {
		for (int i = index + 1; i < size; i++) {
			if (arr[index] < arr[i]) {
				int t = find_long_arr(arr, i, size);
				if (t + 1 > result_arr[index]) {
					result_arr[index] = t + 1;
				}
			}
		}
		if (result_arr[index] == 0) {
			result_arr[index] = 1;
		}
	}
	return result_arr[index];
}
