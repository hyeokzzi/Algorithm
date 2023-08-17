#include<iostream>
#include<unordered_set>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int N;
unordered_set<string> arr;
vector<string> temp;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		string s;
		cin >> name >> s;
		if (s == "enter") arr.insert(name);
		else arr.erase(name);
	}

	for (auto& e : arr) {
		temp.push_back(e);
	}
	sort(temp.rbegin(), temp.rend());
	for (auto& e : temp) {
		cout << e << '\n';
	}

	return 0;
}