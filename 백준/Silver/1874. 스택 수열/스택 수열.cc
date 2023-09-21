#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int N;
int arr[100002];

stack<int> st;
vector<char> ans;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		st.push(i);
		ans.push_back('+');
		while (!st.empty() && st.top() == arr[idx]) {
			idx++;
			st.pop();
			ans.push_back('-');
		}
	}
	if (!st.empty()) {
		cout << "NO";
	}
	else {
		for (auto& e : ans) {
			cout << e << '\n';
		}
	}

}

int main() {
	input();
	solution();

	return 0;
}