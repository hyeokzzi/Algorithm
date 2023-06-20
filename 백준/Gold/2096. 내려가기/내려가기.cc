#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int previous_max[3] = { 0, };
	int previous_min[3] = { 0, };
	
	for (int i = 0; i < N; i++) {
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];

		int after_max[3] = { 0, };
		int after_min[3] = { 99999999,99999999,99999999 };
		for (int j = 0; j < 3; j++) {
			int max_num = 0;
			int min_num = 99999999;
			for (int k = -1; k <= 1; k++) {
				if (j + k >= 0 && j + k <= 2) {
					after_max[j + k] = max(previous_max[j] + arr[j + k], after_max[j + k]);
					after_min[j + k] = min(previous_min[j] + arr[j + k], after_min[j + k]);
				}
			}
		}

		for (int j = 0; j < 3; j++) {
			previous_max[j] = after_max[j];
			previous_min[j] = after_min[j];
		}
	}

	int max_num = 0;
	int min_num = 9999999;
	for (int i = 0; i < 3; i++) {
		max_num = max(max_num, previous_max[i]);
		min_num = min(min_num, previous_min[i]);
	}
	cout << max_num << " " << min_num;
	


	return 0;
}