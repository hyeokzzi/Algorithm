#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
int N, K;
unordered_map<string, int> arr;
vector<string> vec;
int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		string s;
		cin >> s;
		vec.push_back(s);
		if (arr.find(s) == arr.end()) {
			arr.insert({ s,1 });
		}
		else {
			arr[s]++;
		}
	}
	int cnt = 0;
	for (auto& e : vec) {
		if (arr[e] == 1) {
			cout << e << '\n';
			cnt++;
		}
		else {
			arr[e]--;
		}
		if (cnt == N) break;
	}

	return 0;
}