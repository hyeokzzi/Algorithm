#include<iostream>
#include<vector>
using namespace std;
int N;
char arr[7][7];
bool visited[7][7] = { false };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
vector<pair<int, int>> teacher;
vector<pair<int, int>> vec;
int flag = 0;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') vec.push_back({ i,j });
			else if (arr[i][j] == 'T') teacher.push_back({ i,j });
		}
	}
}

void func(int idx, int level) {
	if (level == 3) {
		for (auto& e : teacher) {
			for (int i = 0; i < 4; i++) {
				int y = e.first;
				int x = e.second;
				while (1) {
					if (y < 1 || y > N || x < 1 || x > N) break;
					if (arr[y][x] == 'O') break;
					if (arr[y][x] == 'S') return;
					y += dy[i];
					x += dx[i];
				}
			}
		}
		flag = 1;
		return;
	}
	int size = vec.size();
	for (int i = idx; i < size; i++) {
		if (flag == 1) return;
		int y = vec[i].first;
		int x = vec[i].second;
		arr[y][x] = 'O';
		func(i + 1, level + 1);
		arr[y][x] = 'X';
	}

}


void solution() {
	func(0, 0);
	if (flag == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

int main() {
	input();
	solution();
	

	return 0;
}