#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> arr;

int main() {
	int T;
	cin >> T;
	while (T--) {
		arr.clear();
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			arr.push_back({ a,b });
		}
		sort(arr.begin(), arr.end());
		int idx = 0;
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if (arr[idx].second > arr[i].second) {
				cnt++;
				idx = i;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}