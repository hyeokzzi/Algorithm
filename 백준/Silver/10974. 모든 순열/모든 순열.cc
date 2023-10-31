#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
int visited[9];
int N;
void func() {
	if (arr.size() == N) {
		for (auto& e : arr) {
			cout << e << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr.push_back(i);
				func();
				arr.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	func();

	return 0;
}