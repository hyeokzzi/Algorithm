#include<iostream>
#include<stack>
using namespace std;
stack<int> temp;
int main() {
	string s;
	cin >> s;

	int len = s.length();
	int num = 1;
	int idx = 0;
	while (idx < len) {
		int t = num;
		while (t != 0) {
			temp.push(t % 10);
			t /= 10;
		}

		while (!temp.empty()) {
			if (temp.top() == (s[idx] - '0')) {
				idx++;
			}
			temp.pop();
		}
		num++;
	}
	cout << num - 1;
	
	return 0;
}