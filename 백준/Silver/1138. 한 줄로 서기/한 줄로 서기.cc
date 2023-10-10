#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
vector<int> ans;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		que.push({ num, i + 1 });
	}
}

void solution() {

	ans.push_back(que.top().second);
	que.pop();

	while (!que.empty()) {
		int cnt = que.top().first;
		int num = que.top().second;
		auto it = ans.begin();
		int idx = 0;
		while (it != ans.end()) {
			if (*it > num) {
				if (idx == cnt) break;
				idx++;
			}
			it++;
		}
		ans.insert(it, num);
		que.pop();
	}

	for (auto& e : ans) {
		cout << e << " ";
	}
}

int main() {
	input();
	solution();
	return 0;
}