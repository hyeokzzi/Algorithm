#include<iostream>
#include<vector>
using namespace std;
int N, M;
bool visited[9];
vector<int> arr;
void backtracking(int count) {
	if (count == 0) {
		for (auto& e : arr) {
			cout << e << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		arr.push_back(i);
		backtracking(count-1);
		arr.pop_back();
		visited[i] = false;
	}
}

void solution() {
	cin >> N >> M;
	backtracking(M);
}

int main() {
	solution();

	return 0;
}