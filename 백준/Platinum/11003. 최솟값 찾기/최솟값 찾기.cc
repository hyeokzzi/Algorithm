#include<iostream>
#include<map>
#include<deque>
using namespace std;
int N, L;
int arr[5000001];
deque<pair<int, int>> win;
map<int, int> window; // 수, 개수
void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {

	for (int i = 0; i < N; i++) {
		// 인덱스i / 값 arr[i]
		while (!win.empty() && win.back().first > arr[i]) {
			win.pop_back();
		}
		win.push_back({ arr[i],i });
		if (win.front().second <= i - L) win.pop_front();
		cout << win.front().first << " ";
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