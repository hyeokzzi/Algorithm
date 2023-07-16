#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	int M, K;
	cin >> N >> M >> K;
	int sum = 0;
	vector<int> arr;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		sum += num;
	}

	if (sum < (M * K)) {
		cout << "STRESS";
	}
	else {
		sort(arr.begin(), arr.end());
		int cnt = 0, num = (M * K);
		while (num > 0) {
			num -= arr.back();
			arr.pop_back();
			cnt++;
		}
		cout << cnt;
	}
	return 0;
}