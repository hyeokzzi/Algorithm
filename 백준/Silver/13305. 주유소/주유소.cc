#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int>arr;
set<int> oil;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int distance;
		cin >> distance;
		arr.push_back(distance);
	}
	arr.push_back(0);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		oil.insert(value);

		sum += (arr[i] * (*oil.begin()));
	}
	cout << sum;
	return 0;
}