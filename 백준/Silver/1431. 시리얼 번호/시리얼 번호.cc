#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string a, string b) {
	int len_a = a.length();
	int len_b = b.length();
	if (len_a < len_b)return true;
	else if (len_a == len_b) {
		int cnt_a = 0;
		int cnt_b = 0;
		for (int i = 0; i < len_a; i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) cnt_a += (a[i] - '0');
			if (b[i] - '0' >= 0 && b[i] - '0' <= 9) cnt_b += (b[i] - '0');
		}
		if (cnt_a < cnt_b) return true;
		else if (cnt_a == cnt_b) {
			if (a < b) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

vector<string> arr;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end(), cmp);
	for (auto& e : arr) {
		cout << e << '\n';
	}



	return 0;
}