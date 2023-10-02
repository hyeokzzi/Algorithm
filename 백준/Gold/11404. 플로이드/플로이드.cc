#include<iostream>
#include<vector>
#define INF 210000000
using namespace std;

int N, M;
int dist[101][101];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int st, en, distance;
		cin >> st >> en >> distance;
		dist[st][en] = min(dist[st][en], distance);
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) cout << "0" << " ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

}

int main() {

	input();
	solution();

	return 0;
}