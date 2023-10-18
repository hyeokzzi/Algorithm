#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<string> arr;
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		arr.insert(s);
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (arr.find(s) != arr.end()) cnt++;
	}
	cout << cnt;

	return 0;
}