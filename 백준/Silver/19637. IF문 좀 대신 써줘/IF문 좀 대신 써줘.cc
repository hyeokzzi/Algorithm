#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
set<int>check;
vector<pair<int, string>> arr;
int N, M;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		int score;
		cin >> s >> score;
		int size = check.size();
		check.insert(score);
		if(size != check.size()) arr.push_back({ score, s });
	}
}
int find_idx(int score) {

	int st = 0;
	int en = check.size() - 1;
	while (st < en) {
		int mid = (st + en) / 2;
		if (arr[mid].first >= score) {
			en = mid;
		}
		else st = mid + 1;
	}
	return st;
}



void solution() {
	sort(arr.begin(), arr.end());
	for (int i = 0; i < M; i++) {
		int score;
		cin >> score;
		int idx = find_idx(score);
		cout << arr[idx].second << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}