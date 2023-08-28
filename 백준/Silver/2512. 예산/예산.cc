#include<iostream>
using namespace std;
int N, M;
int arr[10001];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> M;
}

void solution() {

	int under = 0;
	int top = M + 1;
	int mid = (under + top) / 2;
	int flag = 0;
	int max_num = 0;
	while (1) {
		if (flag == 0 && under + 1 == top) flag++;
		else if (flag == 1 && under + 1 == top) break;
		int sum = 0;
		int num = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				sum += mid;
				num = max(num, mid);
			}
			else {
				sum += arr[i];
				num = max(num, arr[i]);
			}
		}
		if (sum > M) {
			top = mid;
		}
		else {
			under = mid;
			max_num = max(max_num, num);
		}
		mid = (top + under) / 2;
	}
	cout << max_num;
}

int main() {
	input();
	solution();

	return 0;
}