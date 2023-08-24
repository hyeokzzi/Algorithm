#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<string, string> umarr;
map<string, vector<string>> marr;
int N, M;


void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		// 멤버 저장
		int num;
		vector<string> temp;
		cin >> num;
		for (int j = 0; j < num; j++) {
			string t;
			cin >> t;
			temp.push_back(t);
			umarr.insert({ t,s });
		}
		sort(temp.begin(), temp.end());
		marr.insert({ s,temp });
	}
}

void solution() {
	for (int i = 0; i < M; i++) {
		int flag;
		string s;
		cin >> s >> flag;
		if (flag == 0) {
			for (auto& e : marr[s]) {
				cout << e << '\n';
			}
		}
		else {
			cout << umarr[s] << '\n';
		}
	}
}

int main() {

	input();
	solution();
	return 0;
}