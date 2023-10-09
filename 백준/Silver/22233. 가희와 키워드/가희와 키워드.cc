#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int N, M;
unordered_set<string> arr;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		arr.insert(s);
	}
}

void solution() {
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		int len = s.length();
		int idx = 0;
		string temp;
		for (int i = 0; i < len; i++) {
			if (s[i] == ',' ) {
				// += '\n';
				arr.erase(temp);
				temp.clear();
			}
			else {
				temp += s[i];
			}
		}
		arr.erase(temp);
		cout << arr.size() << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}