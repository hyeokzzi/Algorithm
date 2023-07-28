#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr;
vector<int> ans;

void func(int level, int idx) {
	if (level == M) {
		for (auto& e : ans) {
			cout << e << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < N; i++) {
		ans.push_back(arr[i]);
		func(level + 1, i);
		ans.pop_back();
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	func(0, 0);


	return 0;
}