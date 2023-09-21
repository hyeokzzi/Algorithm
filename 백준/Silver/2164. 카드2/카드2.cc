#include<iostream>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
int N;
deque<int> arr;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	while (arr.size() != 1) {
		arr.pop_front();

		arr.push_back(arr.front());
		arr.pop_front();
	}
	cout << arr.front();
	return 0;
}