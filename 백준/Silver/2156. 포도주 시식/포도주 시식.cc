#include<iostream>
int arr[10003];
int main() {
	int N;
	std::cin >> N;
	int sum = 0;
	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
		sum += arr[i];
	}

	for (int i = N; i >= 0; i--) {
		int one = arr[i] + arr[i + 1];
		int two = arr[i] + arr[i + 2];
		int three = arr[i] + arr[i + 3];
		arr[i] = std::min(one, two);
		arr[i] = std::min(arr[i], three);
	}
	std::cout << sum - arr[0] << '\n';
	return 0;
}