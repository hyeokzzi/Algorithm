#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {

	int x;
	cin >> x;

	int stick = 64;
	vector<int> arr;
	arr.push_back(stick);

	
	int cnt = 0;
	while (1) {
		sort(arr.begin(), arr.end());
		int sum = 0;
		for (auto& e : arr) {
			sum += e;
		}
		if (sum > x) {
			int len = arr[0] / 2;
			arr.erase(arr.begin());
			arr.push_back(len);

			sum -= len;
			if (sum < x) arr.push_back(len);
		}
		else if (sum == x) break;
	}
	cout << arr.size();

	return 0;
}