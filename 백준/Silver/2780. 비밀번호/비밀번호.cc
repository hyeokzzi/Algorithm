#include<iostream>
#include<vector>
using namespace std;
#define num 1234567

int main() {
	int T;
	cin >> T;
	int pad[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {0,-1,-1} };
	vector<int> surround[10];
	int dx[4] = { 0, 1, 0 , -1 };
	int dy[4] = { -1, 0, 1, 0 };
	// 인접노드 벡터로
	for (int i = 0; i < 10; i++) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 3; y++) {
				if (pad[x][y] == i) {
					for (int k = 0; k < 4; k++) {
						int tx = x + dx[k];
						int ty = y + dy[k];
						if (tx >= 4 || tx < 0 || ty >= 3 || ty < 0) continue;
						if (pad[tx][ty] != -1) {
							surround[i].push_back(pad[tx][ty]);
						}
					}
				}
			}
		}
	}


	// 처리
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		int arr[1001][11] = { 0, };
		for (int j = 0; j <= 9; j++) {
			arr[n][j] = 1;
		}
		for (int j = n - 1; j > 0; j--) {
			for (int k = 0; k < 10; k++) {
				for (auto e : surround[k]) {
					arr[j][k] += (arr[j + 1][e] % num);
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += arr[1][i] % num;
		}
		cout << sum % num << '\n';
	}

	return 0;
}