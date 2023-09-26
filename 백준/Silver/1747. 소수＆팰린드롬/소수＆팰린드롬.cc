#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[2000001];
int main() {
	int N;
	cin >> N;

	for (int i = 2; i <= 2000000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i * i <= 2000000; i++) {
		if (arr[i] == 0) continue;
		for (int j = 2 * i; j <= 2000000; j+= i) {
			arr[j] = 0;
		}
	}


	int num = N;
	while (1) {
		if (arr[num] != 0) {
			// 확인작업
			int tmp = num;
			vector<int> rev;
			while (tmp > 0) {
				rev.push_back(tmp % 10);
				tmp /= 10;
			}
			vector<int> save = rev;
			reverse(rev.begin(), rev.end());

			int size = rev.size();
			int cnt = 0;
			for (int i = 0; i < size; i++) {
				if (rev[i] != save[i]) break;
				cnt++;
			}
			if (cnt == size) {
				cout << num;
				break;
			}
		}
		num++;
	}
	return 0;
}