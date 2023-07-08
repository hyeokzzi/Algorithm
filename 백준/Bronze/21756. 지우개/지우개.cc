#include<iostream>
#include<vector>
using namespace std;
int main() {

	int N;
	cin >> N;
	vector<int> arr1;
	for (int i = 1; i <= N; i++) {
		arr1.push_back(i);
	}
	while (1) {
		if (arr1.size() == 1) {
			cout << arr1.front();
			return 0;
		}
		vector<int> arr2;
		int cnt = 0;
		for (auto e : arr1) {
			cnt++;
			if (cnt % 2 == 1) continue;
			arr2.push_back(e);
		}
		// 초기화
		while (!arr1.empty()) arr1.pop_back();
		for (auto e : arr2) {
			arr1.push_back(e);
		}
	}
	return 0;
}