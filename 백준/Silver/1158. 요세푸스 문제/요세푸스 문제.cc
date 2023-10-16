#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
vector<int> ans;
int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	int idx = 0;
	int cnt = 0;
	while (!arr.empty()) {
		if (cnt != K - 1) {
			cnt++;
			idx++;
		}
		else {
			cnt = 0;
			idx = idx % arr.size();
			ans.push_back(arr[idx]);
			arr.erase(arr.begin() + idx);
		}
	}
	cout << "<";
	while (!ans.empty()) {
		if (ans.size() != 1) {
			cout << ans.front() << ", ";
		}
		else {
			cout << ans.front();
		}
		ans.erase(ans.begin());
	}
	cout << ">";
	return 0;
}