#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
typedef struct{
	int num;
	int idx;
}node;
bool cmp(node a, node b) {
	if (a.num < b.num) return true;
	return false;
}
vector<pair<int,int>> vec;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back({ num, i });
	}
}

void solution() {
	sort(vec.begin(), vec.end());

	int idx = 0;
	int max_diff = 0;
	for (int i = 0; i < N; i++) {
		max_diff = max(vec[i].second - i, max_diff);
	}
	
	cout << max_diff + 1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solution();
	return 0;
}