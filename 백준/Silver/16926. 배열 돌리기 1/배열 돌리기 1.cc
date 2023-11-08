#include<iostream>
using namespace std;
int N, M, R;
int arr[301][301];

void input() {
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

void swap(int b, int a, int y, int x) {
	int temp = arr[b][a];
	arr[b][a] = arr[y][x];
	arr[y][x] = temp;
}

void solution() {

	while (R--) {
		bool visited[301][301] = { false };

		int t = 1;
		while (!visited[t][t]) {
			int temp = arr[t][t];
			for (int i = t; i <= M - t; i++) {
				swap(t, i, t, i + 1);
				visited[t][i] = true;
			}

			for (int i = t; i <= N - t; i++) {
				swap(i, M - t + 1, i + 1, M - t + 1);
				visited[i][M - t + 1] = true;
			}

			for (int i = M - t + 1; i > t; i--) {
				swap(N - t + 1, i, N - t + 1, i - 1);
				visited[N - t + 1][i] = true;
			}

			for (int i = N - t + 1; i > t + 1; i--) {
				swap(i, t, i - 1, t);
				visited[i][t] = true;
			}
			t++;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}


}

int main() {
	input();
	solution();
	return 0;
}