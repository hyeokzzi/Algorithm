#include<iostream>
int arr[100001];

int main() {
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}
	int max = -1001;
	for (int i = 1; i <= N; i++) {
		arr[i] = std::max(arr[i], arr[i] + arr[i - 1]);
		if (arr[i] > max) max = arr[i];
	}
	std::cout << max;
	return 0;
}