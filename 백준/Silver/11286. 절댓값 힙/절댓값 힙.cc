#include<iostream>
#include<queue>

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) {
			return true;
		}
		else if (abs(a) < abs(b)) {
			return false;
		}
		else {
			if (a > b) {
				return true;
			}
			else return false;
		}
	}
};
std::priority_queue<int, std::vector<int>, compare> arr;
int main() {

	int N;
	std::cin >> N;
	int index = 0;
	for (int i = 0; i < N; i++) {

		int num;
		std::cin >> num;
		if (num != 0) {
			arr.push(num);
		}
		else {
			if (arr.empty() == true) {
				std::cout << '0' << '\n';
			}
			else {
				std::cout << arr.top() << '\n';
				arr.pop();

			}
		}
	}

	return 0;
}