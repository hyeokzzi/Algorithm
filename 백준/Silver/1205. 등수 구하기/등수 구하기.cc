#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
int main() {
	int N, score, P;
	cin >> N >> score >> P;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.rbegin(), arr.rend());
	int cnt = 0;
	int bigger_cnt = 0;
	for (auto& e : arr) {
		if (e >= score) {
			if (e > score) {
				bigger_cnt++;
			}
			cnt++;
		}
	}
	if (cnt < P) {
		cout << bigger_cnt + 1;
	}
	else {
		cout << "-1";
	}

	return 0;
}