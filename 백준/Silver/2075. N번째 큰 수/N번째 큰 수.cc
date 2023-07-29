#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> arr;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			arr.push(num);
			if (arr.size() > N) arr.pop();
		}
	}
	cout << arr.top();
	return 0;
}