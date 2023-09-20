#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		// 음수가 있음
		int start_idx = 0;
		int end_idx = N - 1;
		while (start_idx < end_idx) {
			if (arr[start_idx] + arr[end_idx] < arr[i]) {
				start_idx++;
			}
			else if (arr[start_idx] + arr[end_idx] > arr[i]) {
				end_idx--;
			}
			else {
				if (start_idx != i && end_idx != i) {
					cnt++;
					break;
				}
				else {
					if (start_idx == i) start_idx++;
					else if (end_idx == i) end_idx--;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}