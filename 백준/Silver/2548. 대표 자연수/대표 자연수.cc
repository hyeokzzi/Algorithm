#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[20001];
bool visited[20001] = { false };
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int min_sum = 2100000000;
	vector<int> save;
	for (int i = 0; i < N; i++) {
		if (visited[arr[i]] == true) continue;
		visited[arr[i]] = true;
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += abs(arr[i] - arr[j]);
		}
		if (sum < min_sum) {
			while (!save.empty()) save.pop_back();
			save.push_back(arr[i]);
			min_sum = sum;
		}
		else if (sum == min_sum) {
			save.push_back(arr[i]);
		}
	}

	sort(save.begin(), save.end());
	cout << save.front();


	return 0;
}