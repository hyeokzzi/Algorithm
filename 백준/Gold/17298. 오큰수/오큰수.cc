#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int N, arr[1000001];
queue<int> que;
stack<int> st;
int ans[1000001] = { 0, };
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solution() {

	for (int i = 1; i <= N; i++) {
		while (!st.empty() && arr[st.top()] < arr[i]) {
			ans[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		ans[st.top()] = -1;
		st.pop();
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}

}

int main() {
	input();
	solution();

	return 0;
}