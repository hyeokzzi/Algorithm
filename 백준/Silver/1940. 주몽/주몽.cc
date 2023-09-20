#include<iostream>
#include<vector>	
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}
void solution() {
	sort(arr.begin(), arr.end());
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] + arr[j] == M) cnt++;
			else if (arr[i] + arr[j] > M) break;
		}
	}
	cout << cnt;
}
int main() {
	input();
	solution();
	return 0;
}