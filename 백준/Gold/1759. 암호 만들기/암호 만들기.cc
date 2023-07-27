#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<char> vec;
vector<char> ans;
int C, L;

void func(int level, int idx) {
	if (level == L) {
		int cnt = 0;
		for (auto& e : ans) {
			if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u')cnt++;
		}
		if (cnt >= 1 && cnt <= L - 2) {
			for (auto& e : ans) {
				cout << e;
			}
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		ans.push_back(vec[i]);
		func(level + 1, i + 1);
		ans.pop_back();
	}
}

int main() {

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());

	// 모음 1개 / 자음 두개
	func(0,0);
	return 0;
}