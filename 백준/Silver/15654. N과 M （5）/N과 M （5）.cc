#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr;
bool visited[8] = { false };
vector<int> save;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}

void recursive(int count) {

	if (count == 0) {
		for (auto e : save) {
			cout << e << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		else {
			visited[i] = true;
			save.push_back(arr[i]);
			recursive(count - 1);
			save.pop_back();
			visited[i] = false;
		}
	}

}


void solve() {
	sort(arr.begin(), arr.end());
	recursive(M);
}

int main() {
	input();
	solve();
	return 0;
}