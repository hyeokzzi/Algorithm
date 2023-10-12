#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<int> arr;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)	{
		int num;
		cin >> num;
		arr.insert(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (arr.find(num) == arr.end()) cout << "0 ";
		else cout << "1 ";
	}
	return 0;
}