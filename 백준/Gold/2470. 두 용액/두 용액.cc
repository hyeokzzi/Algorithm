#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<int>vec;
int N;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
}
void solution() {
	sort(vec.begin(), vec.end());
	int min_diff = 2100000000;
	int start_idx = 0, end_idx = N - 1;
	int sm = 0, bi = 0;
	while (start_idx < end_idx) {
		int sum = vec[start_idx] + vec[end_idx];
		if (abs(sum) < min_diff) {
			sm = min(vec[start_idx], vec[end_idx]);
			bi = max(vec[start_idx], vec[end_idx]);
			min_diff = abs(sum);
		}

		if (sum < 0)start_idx++;
		else end_idx--;
	}
	cout << sm << " " << bi;
}


int main() {
	input();
	solution();

	return 0;
}