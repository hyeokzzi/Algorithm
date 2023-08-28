#include<iostream>
#include<set>
using namespace std;
int N, M;
set<int> arr;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.insert(num);
	}
}

void solution() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (arr.find(num) == arr.end()) {
			cout << '0' << '\n';
		}
		else {
			cout << '1' << '\n';
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	input();
	solution();
	return 0;
}