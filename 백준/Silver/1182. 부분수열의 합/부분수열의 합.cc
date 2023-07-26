#include<iostream>
#include<vector>
using namespace std;
int N, sum;
int arr[20];
bool visited[20];
vector<int> vec;
int cnt = 0;

void backtracking(int idx) {
	if (!vec.empty()) {
		int t = 0;
		for (auto& e : vec) {
			t += e;
		}
		if (t == sum) {
			cnt++;
		}
	}

	for (int i = idx; i < N; i++) {
		vec.push_back(arr[i]);
		backtracking(i + 1);
		vec.pop_back();
	}

}


int main() {
	cin >> N >> sum;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	backtracking(0);
	cout << cnt;
	return 0;
}