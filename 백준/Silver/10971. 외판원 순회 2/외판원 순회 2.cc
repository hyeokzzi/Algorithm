#include<iostream>
using namespace std;
int N, arr[11][11];
bool visited[11] = { false };
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

int min_cost = 2100000000;
int sum = 0;
void func(int start_idx, int idx, int cnt) {
	if (cnt == N - 1) {
		if (arr[idx][start_idx] == 0) return;
		sum += arr[idx][start_idx];
		min_cost = min(min_cost, sum);
		sum -= arr[idx][start_idx];
		return;
	}
	if (sum >= min_cost) return;
	for (int i = 1; i <= N; i++) {
		if (i == start_idx) continue;
		if (visited[i] || arr[idx][i] == 0) continue;
		sum += arr[idx][i];
		visited[i] = true;
		func(start_idx, i, cnt + 1);
		visited[i] = false;
		sum -= arr[idx][i];
	}
}
void solution() {
	for (int i = 1; i <= N; i++) {
		visited[i] = true;
		func(i, i, 0);
		visited[i] = false;
	}
	cout << min_cost;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}