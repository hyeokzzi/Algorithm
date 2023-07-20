#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
int N, flag = 0;
int arr[101];
vector <int> save;
set <int> ans;
bool visited[101] = { false };
int max_size = 0;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}


void dfs(int idx) {
	// 방문처리
	visited[idx] = true;
	int num = arr[idx];
	if (visited[num] == true) {
		if (num == save.front()) flag = 1;
		else return;
	}
	else {
		save.push_back(num);
		dfs(num);
	}
}


int main() {
	input();
	for (int i = 1; i <= N; i++) {
		flag = 0;
		memset(visited, 0, sizeof(visited));
		while (!save.empty()) save.pop_back();
		save.push_back(i);
		dfs(i);
		if (flag == 1) {
			for (auto e : save) {
				ans.insert(e);
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto e : ans) {
		cout << e << '\n';
	}
	return 0;
}