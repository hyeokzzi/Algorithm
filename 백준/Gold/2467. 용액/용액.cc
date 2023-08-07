#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
vector<int>arr;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}

int min_sum = 2000000001;
int save_idx1 = 0;
int save_idx2 = 0;
void solution() {
	// 확인 -> 비교 -> 저장 -> 확인
	for (int i = 0; i < N-1; i++) {
		int start_idx = i + 1;
		int end_idx = N;
		int cur_idx = (start_idx + end_idx) / 2;
		int flag = 0;
		while (1) {
			// ㅡㅡㅡㅡㅡㅡㅡㅡ 종료조건 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
			if (flag == 1) break;
			if (start_idx + 1 == end_idx) {
				flag = 1;
			}
			// ㅡㅡㅡㅡㅡㅡㅡㅡㅡ 저장 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
			int sum = arr[i] + arr[cur_idx];
			if (abs(sum) < min_sum) {
				save_idx1 = i;
				save_idx2 = cur_idx;
				min_sum = abs(sum);
			}
			// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
			if (sum > 0) {
				end_idx = cur_idx;
				cur_idx = (end_idx + start_idx) / 2;
			}
			else if (sum < 0) {
				start_idx = cur_idx;
				cur_idx = (end_idx + start_idx) / 2;
			}
			else {
				// 정답 -> 바로 리턴해도 됨.
				cout << arr[i] << " " << arr[cur_idx];
				return;
			}
		}
	}
	cout << arr[save_idx1] << " " << arr[save_idx2];
}


int main() {
	input();
	solution();
	return 0;
}