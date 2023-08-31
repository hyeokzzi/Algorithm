#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N, M;
typedef struct {
	string word;
	int value;
} node;

map<string, int> inp;
vector<node> arr;

bool cmp(node a,  node b) {
	if (a.value > b.value) return true;
	else if (a.value == b.value) {
		if (a.word.length() > b.word.length()) return true;
		else if (a.word.length() == b.word.length()) {
			if (a.word < b.word) return true;
			else return false;
		}
	}
	return false;
}


void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i ++ ) {
		string s;
		cin >> s;
		if (s.length() >= M) {
			if (inp.find(s) == inp.end()) {
				inp.insert({ s,1 });
			}
			else {
				inp[s]++;
			}
		}
	}
}

void solution() {
	for (auto& e : inp) {
		node temp;
		temp.word = e.first;
		temp.value = e.second;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), cmp);
	for (auto& e : arr) {
		cout << e.word << '\n';
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
