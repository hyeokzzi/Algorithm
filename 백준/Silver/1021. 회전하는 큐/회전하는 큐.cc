#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<int> vec;
deque<int> arr;
int N, M;
int min_cnt = 21000000;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	int cnt = 0;
	for (auto& e : vec) {
		// 어느쪽이 가까운지 판단
		int front_cnt = 0;
		int back_cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == e) {
				front_cnt = i;
				back_cnt = arr.size() - i;
				break;
			}
		}

		// 뒤로 이동
		if (front_cnt > back_cnt) {
			cnt += back_cnt;
			while (back_cnt > 0) {
				arr.push_front(arr.back());
				arr.pop_back();
				back_cnt--;
			}
		}
		// 앞으로 이동
		else {
			cnt += front_cnt;
			while (front_cnt > 0) {
				arr.push_back(arr.front());
				arr.pop_front();
				front_cnt--;
			}
		}
		arr.pop_front();
	}
	cout << cnt;


	return 0;
}