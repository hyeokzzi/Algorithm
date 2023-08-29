#include<iostream>
#include<vector>
using namespace std;
int T;
int main() {
	cin >> T;
	while (1) {
		int num;
		cin >> num;
		int sum = 0;
		vector<int> arr;
		for (int i = 0; i < 20; i++) {
			int height;
			cin >> height;
			int cnt = 0;
			arr.push_back(height);
			for (auto& e : arr) {
				if (e < height) cnt++;
			}
			sum += (arr.size() - cnt - 1);
		}
		cout << num << " " << sum << '\n';
		if (num == T) break;
	}

	return 0;
}