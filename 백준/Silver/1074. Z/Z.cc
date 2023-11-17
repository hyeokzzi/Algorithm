#include<iostream>
int sum = 0;

void find_idx(int row, int col, int size) 
{
	int mid = size / 2;
	int t = 0;
	if (row < mid) {
		// #1
		if (col < mid) {
			sum += 0;
			if (mid != 1) {
				find_idx(row, col, mid);
			}
		}
		// #2
		else {
			t = (mid * mid);
			sum += t;
			if (mid != 1) {
				find_idx(row, col - mid, mid);
			}
		}
	}
	else {
		// #3
		if (col < mid) {
			t = (2 * mid * mid);
			sum += t;
			if (mid != 1) {
				find_idx(row - mid, col, mid);
			}
		}
		// #4
		else {
			t = (3 * mid * mid);
			sum += t;
			if (mid != 1) {
				find_idx(row - mid, col - mid, mid);
			}
		}
	}
}



int main() 
{
	int N, r, c;
	std::cin >> N >> r >> c;
	int size = 1;
	for (int i = 0; i < N; i++)
	{
		size *= 2;
	}
	find_idx(r, c, size);
	std::cout << sum;

	return 0;
}