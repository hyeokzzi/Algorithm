#include<iostream>
using namespace std;
int N, M, K;
int arr[301][301];
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 1; i <= M; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			arr[j][i] += arr[j - 1][i];
		}
	}
}

void solution() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int sum = arr[y2][x2] - arr[y1 - 1][x2] - arr[y2][x1 - 1] + arr[y1 - 1][x1 - 1];
		cout << sum << '\n';
	}

}


int main() {
	input();
	solution();
	

	return 0;
}