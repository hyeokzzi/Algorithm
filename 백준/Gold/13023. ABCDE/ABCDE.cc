#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> arr[2001];
bool visited[2001] = { false };
int flag = 0;
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
}

void dfs(int idx, int cnt) {
	if (cnt == 5) {
		flag = 1;
		return;
	}
	for (auto& e : arr[idx]) {
		if (visited[e] == false) {
			visited[e] = true;
			dfs(e, cnt + 1);
			visited[e] = false;
		}
	}
}


int main() {

	input();
	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i, 1);
		visited[i] = false;
		if (flag == 1) {
			cout << "1";
			return 0 ;
		}
	}
	cout << "0";
	return 0;
}