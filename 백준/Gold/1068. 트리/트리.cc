#include<iostream>
#include<vector>
using namespace std;
int N, root, dNode, ans = 0;
vector<int> arr[51];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			root = i;
		}
		else {
			arr[num].push_back(i);
		}
	}
	cin >> dNode;
	return;
}

void dfs(int idx) {
	if (idx == dNode) return;
	int cnt = 0;
	for (auto& e : arr[idx]) {
		if (e == dNode) continue;
		cnt++;
		dfs(e);
	}
	if (cnt == 0) ans++;
}


int main() {
	input();
	dfs(root);
	cout << ans;
	return 0;
}