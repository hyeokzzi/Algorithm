#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	while (N--) {
		string s;
		stack<char> ans;
		stack<char> st;
		cin >> s;

		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (s[i] == '>') {
				if (!st.empty()) {
					ans.push(st.top());
					st.pop();
				}
			}
			else if (s[i] == '<') {
				// 커서 뒤문자들 저장
				if (!ans.empty()) {
					st.push(ans.top());
					ans.pop();
				}
			}
			// 문자 지움 
			else if (s[i] == '-') {
				if (!ans.empty())ans.pop();
			}
			// 문자 넣기
			else {
				ans.push(s[i]);
			}
		}
		
		while (!st.empty()) {
			ans.push(st.top());
			st.pop();
		}
		deque<char> print;
		while (!ans.empty()) {
			print.push_front(ans.top());
			ans.pop();
		}
		for (auto& e : print) {
			cout << e;
		}
		cout << '\n';
	}
	return 0;
}