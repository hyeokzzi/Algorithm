#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> arr;
bool visited[5001] = { false };

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) arr.push_back(i);

	int level = 1;
	int last_idx = 0;
	while (arr.size() != 1) {
		long long idx = pow(level % arr.size(), 3);
		idx = (idx + last_idx) % arr.size(); 
		if (idx == 0) {
			arr.erase(arr.begin() + arr.size() - 1);
			last_idx = 0;
		}
		else {
			arr.erase(arr.begin() + idx - 1);
			last_idx = idx - 1;
		}
		level++;
	}
	cout << arr.front();
	return 0;
}