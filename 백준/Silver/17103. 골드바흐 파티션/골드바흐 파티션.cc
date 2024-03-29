#include<iostream>
#include<vector>
#include<set>
using namespace std;
int arr[1000001];
vector<int> vec;
set<int> s;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i < 1000001; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] == i) {
			for (int j = i * 2; j <= 1000000; j+=i) arr[j] = 0;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int N;
		int cnt = 0;
		cin >> N;
		for (int i = 2; i <= N / 2; i++) {
			if (arr[i] != 0 && arr[N - i] != 0) cnt++;
		}
		cout << cnt << '\n';
	}


	return 0;
}