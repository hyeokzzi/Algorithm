#include<iostream>
#include<vector>
using namespace std;
int N;
int arr[500001];
vector<int> vec;
vector<int> ans;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		while (!vec.empty() && arr[i] > arr[vec.back()]) {
			vec.pop_back();
		}
		if (vec.empty()) ans.push_back(0);
		else ans.push_back(vec.back());
		vec.push_back(i);
	}
	for (auto& e : ans) {
		cout << e << " ";
	}

}

int main() {
	input();
	solution();
	return 0;
}