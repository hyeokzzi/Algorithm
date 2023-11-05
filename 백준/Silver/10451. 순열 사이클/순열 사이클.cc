#include<iostream>
#include<vector>
using namespace std;
int T, N;
int arr[1001];
bool visited[1001] = { false };

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void func(int idx) {
	visited[idx] = true;
	if (visited[arr[idx]]) return;

}

void solution() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		int idx = i;
		visited[idx] = true;
		while (!visited[arr[idx]]) {
			visited[arr[idx]] = true;
			idx = arr[idx];
		}
		cnt++;
	}
	cout << cnt << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		// 초기화
		for (int i = 0; i <= 1000; i++) {
			visited[i] = false;
			arr[i] = 0;
		}
		input();
		solution();
	}
	return 0;
}