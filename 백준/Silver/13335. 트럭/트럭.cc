#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int arr[1001];
deque<pair<int, int>> vec;
int main() {
	int N, L, W;
	cin >> N >> L >> W;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {

		if (sum + arr[i] > W) {
			while (sum + arr[i] > W) {
				sum -= vec.front().first;
				cnt += vec.front().second;
				int num = vec.front().second;
				for (auto& e : vec) {
					e.second -= num;
				}
				vec.pop_front();
			}
		}
		else {
			for (auto& e : vec) {
				e.second--;
			}
			if (!vec.empty() && vec.front().second == 0) {
				sum -= vec.front().first;
				vec.pop_front();
			}
			cnt++;
		}
		vec.push_back({ arr[i],L });
		sum += arr[i];
	}
	cnt += vec.back().second;
	cout << cnt;



	return 0;
}