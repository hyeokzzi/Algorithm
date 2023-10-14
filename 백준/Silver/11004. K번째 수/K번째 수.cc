#include<iostream>
#include<vector>	
#include<algorithm>
using namespace std;
vector<int > arr;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cout << arr[K - 1];
	return 0;
}