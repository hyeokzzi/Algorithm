#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<cmath>
using namespace std;
int N;
vector<int> arr;
vector<int> ans;
bool visited[9] = { false };
int max_sum = 0;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}
void func() {
	if (ans.size() == N) {
		int sum = 0;
		for (int i = 1; i < N; i++) {
			sum += abs(ans[i] - ans[i - 1]);
		}
		max_sum = max(max_sum, sum);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		ans.push_back(arr[i]);
		visited[i] = true;
		func();
		visited[i] = false;
		ans.pop_back();
	}
}

int main() {
	input();
	func();
	cout << max_sum;
	return 0;
}