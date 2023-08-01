#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> que;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int N;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		arr.push_back({ s,e });
	}
}

void solution() {
	int cnt = 0;
	que.push(arr[0].second);
	for (int i = 1; i < N; i++) {
		if (que.top() <= arr[i].first) {
			que.pop();
			que.push(arr[i].second);
		}
		else {
			que.push(arr[i].second);
		}
	}
	cout << que.size();
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	input();
	sort(arr.begin(), arr.end(), cmp);
	solution();

	return 0;
}