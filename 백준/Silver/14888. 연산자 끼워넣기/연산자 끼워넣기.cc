#include<iostream>
using namespace std;
int N;
int cal[4], arr[12];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
	}
}
int min_sum = 2000000000;
int max_sum = -2000000000;
void dfs(int sum, int idx) {
	
	if (idx == N) {
		min_sum = min(min_sum, sum);
		max_sum = max(max_sum, sum);
		return;
	}

	if (cal[0] != 0) {
		int temp = sum + arr[idx];
		cal[0]--;
		dfs(temp, idx + 1);
		cal[0]++;
	}
	if (cal[1] != 0) {
		int temp = sum - arr[idx];
		cal[1]--;
		dfs(temp, idx + 1);
		cal[1]++;
	}
	if (cal[2] != 0) {
		int temp = sum * arr[idx];
		cal[2]--;
		dfs(temp, idx + 1);
		cal[2]++;
	}
	if (cal[3] != 0) {
		int temp = sum / arr[idx];
		cal[3]--;
		dfs(temp, idx + 1);
		cal[3]++;
	}
}

void solution() {
	dfs(arr[0], 1);
	cout << max_sum << '\n' << min_sum;
}

int main() {
	input();
	solution();

	return 0;
}