#include<iostream>
#include<vector>	
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}
void solution() {
	sort(arr.begin(), arr.end());
	int cnt = 0;
	int start_idx = 0;
	int end_idx = N - 1;
	while (start_idx < end_idx) {
		if (arr[start_idx] + arr[end_idx] > M) {
			end_idx--;
		}
		else if (arr[start_idx] + arr[end_idx] < M) {
			start_idx++;
		}
		else {
			start_idx++;
			end_idx--;
			cnt++;
		}
	}
	cout << cnt;
}
int main() {
	input();
	solution();
	return 0;
}