#include<iostream>
#include<queue>
using namespace std;
int arr[1001], n, m;
priority_queue<long long, vector<long long>, greater<long long>> que;
void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		que.push(arr[i]);
	}
}

void solution() {
	while (m--) {
		long long sum = 0;
		for (int i = 0; i < 2; i++) {
			sum += que.top();
			que.pop();
		}
		for (int i = 0; i < 2; i++) que.push(sum);
	}

	int size = que.size();
	long long sum = 0;
	for (int i = 0; i < size; i++) {
		sum += que.top();
		que.pop();
	}
	cout << sum;
}

int main() {
	input();
	solution();
	return 0;
}