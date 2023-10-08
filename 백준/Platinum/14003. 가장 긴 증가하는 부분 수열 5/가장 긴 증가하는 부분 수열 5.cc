#include<iostream>
#include<vector>
using namespace std;
int N, end_idx = 0, max_cnt = 0;
int arr[1000001];
int dp[1000001];
int save[1000001]; // 가장 최근수 중 idx만큼 작은 수를 가진애 저장용

int BinarySearch(int st, int en, int value) {
	int mid;
	while (st < en) {
		mid = (st + en) / 2;
		if (save[mid] < value) {
			st = mid + 1;
		}
		else en = mid;
	}
	return st;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// (n+1) * n/2 => n^2 시간복잡도 -> 시간초가
	dp[1] = 1;
	save[1] = arr[1];
	max_cnt = 1;
	for (int i = 2; i <= N; i++) {
		// 가장 큰것보다 숫자가 큰 경우 새로 배열에 추가
		// save배열 if save = {1, 2, 3} => save = {1, 2, 3, 현재값}; 
		if (save[max_cnt] < arr[i]) {
			dp[i] = max_cnt + 1;
			max_cnt++;
			save[max_cnt] = arr[i];
		}
		// 기존에 있는 값과 비교해서 작은 수 다음 인덱스 받아옴
		// if arr[i] = 10, save배열 5 27 36 ==> save 배열 5 10 36d으로 변경됨.
		else {
			int idx = BinarySearch(1, max_cnt, arr[i]);
			save[idx] = arr[i];
			dp[i] = idx;
		}
	}
	vector<int>ans;
	int idx = max_cnt;
	int num = save[max_cnt] + 1;
	cout << max_cnt << '\n';
	for (int i = N; i >= 1; i--) {
		if (dp[i] == idx && arr[i] < num) {
			ans.push_back(arr[i]);
			num = arr[i];
			idx--;
		}
	}
	// 출력
	int size = ans.size();
	for (int i = size - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	
	return 0;
}