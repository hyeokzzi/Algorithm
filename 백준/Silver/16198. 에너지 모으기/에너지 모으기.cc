#include<iostream>
#include<vector>
using namespace std;
int N;
int arr[11];
int visited[11];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i + 1];
	}
}

int dfs(int idx) {
	visited[idx] = 1;
	int max_sum = 0;
	int minus_idx = idx- 1;
	int plus_idx = idx + 1;
	while (visited[minus_idx] != 0)minus_idx--;
	while (visited[plus_idx] != 0) plus_idx++;
	int sum = arr[minus_idx] * arr[plus_idx];
	for (int i = 2; i < N; i++) {
		if (visited[i] == 1) continue;
		max_sum = max(max_sum, dfs(i));
	}
	visited[idx] = 0;
	return max_sum + sum;
}


void solve() {
	int max_sum = 0;
	for (int i = 2; i < N; i++) {
		max_sum = max(max_sum,dfs(i));
	}
	cout << max_sum;



}


int main() {
	input();
	solve();



	return 0;
}