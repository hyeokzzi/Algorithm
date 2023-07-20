#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> ans;
int A, B, C;
int water[3];
bool visited[201][201][201] = { false };
void dfs(int x, int y, int z) {
	visited[x][y][z] = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int arr[3] = { x, y, z };
			if (i == j) continue;
			if (arr[i] == 0 || arr[j] == water[j]) continue;
			// 받을 수 있는 양
			int empty = water[j] - arr[j];
			// 줄수있는게 더 많을 때
			if (arr[i] >= empty) {
				arr[j] += empty;
				arr[i] -= empty;
			}
			else {
				arr[j] += arr[i];
				arr[i] = 0;
			}
			if (visited[arr[0]][arr[1]][arr[2]] == true) continue;
			if (arr[0] == 0) {
				ans.insert(arr[2]);
			}
			dfs(arr[0], arr[1], arr[2]);
		}
	}
}




int main() {
	for (int i = 0; i < 3; i++) {
		cin >> water[i]; // A B C
	}
	ans.insert(water[2]);
	dfs(0, 0, water[2]);
	for (auto& e : ans) {
		cout << e << " ";
	}
	return 0;
}