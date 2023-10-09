#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
long long dp[1000001];
long long arr[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		stack<pair<int, int>> st; // num, size
		st.push({ arr[1], 1 });
		for (int i = 2; i <= N; i++) {
			int size = 0;
			long long sum = 0;
			while (!st.empty()) {
				if (st.top().first < arr[i]) {
					size += st.top().second;
					sum += ((arr[i] - st.top().first) * st.top().second);
					st.pop();
				}
				else break;
			}
			st.push({ arr[i], size + 1});
			dp[i] = dp[i-1] + sum;
		}
		cout << dp[N] << '\n';
		
	}

	return 0;
}