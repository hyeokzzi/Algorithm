#include<iostream>
#include<vector>
#include<set>
using namespace std;
int arr[1000001];
vector<int>vec;
set<int> setArr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i <= 1000000; i++) arr[i] = i;
	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] != i) continue;
		vec.push_back(i);
		setArr.insert(i);
		for (int j = 2 * i; j <= 1000000; j += i) arr[j] = 0;
	}
	int size = vec.size();

	while (1) {
		int N, a = 0, b = 0;
		bool pos = false;
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < size; i++) {
			if (arr[N - vec[i]] == N - vec[i]) {
				pos = true;
				cout << N << " = " << vec[i] << " + " << N - vec[i] << '\n';
				break;
			}
		}

		// 출력
		if (!pos) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}

	return 0;
}