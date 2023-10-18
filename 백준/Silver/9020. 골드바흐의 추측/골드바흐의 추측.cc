#include<iostream>
#include<vector>
using namespace std;
int arr[10001];
int T;
vector<int> vec;
pair<int, int> ans;
int main() {
	cin >> T;
	for (int i = 2; i <= 10000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= 10000; i++) {
		if (arr[i] != i) continue;
		vec.push_back(i);
		for (int j = i * 2; j <= 10000; j += i) arr[j] = 0;
	}

	int size = vec.size();
	while (T--) {
		int N;
		cin >> N;
		ans = { 0, 10001 };
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (vec[i] + vec[j] > N) break;
				if (vec[i] + vec[j] == N && vec[j] - vec[i] < ans.second - ans.first) {
					ans.first = vec[i];
					ans.second = vec[j];
				}
			}
		}
		cout << ans.first << " " << ans.second << '\n';
	}

	return 0;
}