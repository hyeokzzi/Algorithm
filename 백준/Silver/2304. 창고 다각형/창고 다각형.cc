#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, L, H;
int left_x, right_x;
//vector<pair<int, int>> arr;
priority_queue<pair<int, int>> que;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L >> H;
		que.push({ H,L });
	}
}

void solution() {
	left_x = que.top().second;
	right_x = left_x + 1;
	int sum = (right_x - left_x) * que.top().first;
	que.pop();

	while (!que.empty()) {
		int x = que.top().second;
		int h = que.top().first;
		que.pop();
		// left보다 작거나 같을때
		if (x <= left_x) {
			sum += (left_x - x) * h;
			left_x = x;
		}
		else if (x + 1 >= right_x) {
			sum += ((x + 1) - right_x) * h;
			right_x = x + 1;
		}
	}
	cout << sum;
}


int main() {

	input();
	solution();

	return 0;
}