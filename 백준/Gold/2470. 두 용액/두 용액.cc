#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<pair<int,int>>vec;
priority_queue<int> arr;
int N;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num, flag = 1;
		cin >> num;
		if (num < 0) flag = -1;
		else if (num == 0) flag = 2;
		vec.push_back({ abs(num), flag }); // 양수 0 음수 1
	}

}

int min_diff = 2100000000;
void solution() {
	sort(vec.begin(), vec.end());
	int size = vec.size();
	int small_num = -1;
	int big_num = -1;
	for (int i = 1; i < size; i++) {
		int num1 = 0;
		int num2 = 0;
		if (vec[i - 1].second != vec[i].second) {
			num1 = vec[i - 1].first * vec[i - 1].second;
			num2 = vec[i].first * vec[i].second;
		}
		else {
			num1 = vec[i - 1].first * vec[i - 1].second;
			num2 = vec[i].first * vec[i].second;
		}
		if (min_diff > abs(num1 + num2)) {
			small_num = min(num1, num2);
			big_num = max(num1, num2);
			min_diff = abs(num1 + num2);
		}
	}
	// 한쪽만 있는 경우
	cout << small_num << " " << big_num;

}

int main() {
	input();
	solution();

	return 0;
}