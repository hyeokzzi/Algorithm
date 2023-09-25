#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
int arr[51];
int N;

priority_queue<int, vector<int>, less<int>> pq_plus;
priority_queue<int, vector<int>, greater<int>> pq_minus;
int sum = 0;
void input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		if (num < 0) {
			pq_minus.push(num);
		}
		else {
			pq_plus.push(num);
		}
	}
}

void solution() {
	// 양수 곱 덧셈
	while (pq_plus.size() >= 2) {
		int value1 = pq_plus.top();
		if (value1 == 0 || value1 == 1) break;
		pq_plus.pop();

		int value2 = pq_plus.top();
		if (value2 == 0 || value2 == 1) {
			pq_plus.push(value1);
			break;
		}
		pq_plus.pop();
		sum += (value1 * value2);
	}
	// 1 더해줌
	while (!pq_plus.empty() && pq_plus.top() != 0) {
		sum += pq_plus.top();
		pq_plus.pop();
	}

	// 음수 곱 덧셈
	while (pq_minus.size() >= 2) {
		int value1 = pq_minus.top();
		pq_minus.pop();

		int value2 = pq_minus.top();
		pq_minus.pop();

		sum += (value1 * value2);
	}

	while (!pq_minus.empty()) {
		if (!pq_plus.empty()) {
			pq_plus.pop();
		}
		else {
			sum += pq_minus.top();
		}
		pq_minus.pop();
	}
	cout << sum;
}

int main() {
	input();
	solution();

	return 0;
}