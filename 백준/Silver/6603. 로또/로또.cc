#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
vector<int> vec;
vector<int> arr;
void input() {
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}

void print() {
	for (auto e : vec) {
		cout << e << " ";
	}
	cout << '\n';
}

void recursive(int idx) {
	if (vec.size() == 6) {
		print();
	}
	else {
		for (int i = idx; i < n; i++) {
			vec.push_back(arr[i]);
			recursive(i + 1);
			vec.pop_back();
		}
	}
}

void solve() {
	while (!vec.empty())vec.pop_back();
	while (!arr.empty())arr.pop_back();
	input();
	recursive(0);
}

int main() {
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		solve();
		cout << '\n';
	}
	return 0;
}