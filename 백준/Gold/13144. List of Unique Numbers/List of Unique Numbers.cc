#include<iostream>
using namespace std;
int N;
int arr[100001];
int visited[100001];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {

	int end = 0;
	long long cnt = 0;
	int flag = 0;
	int temp_value = -1;
	for (int i = 0; i < N; i++) {
		while (end < N && flag == 0) {
			if (visited[arr[end]] == 1) {
				flag++;
				temp_value = arr[end];
				break;
			}
			visited[arr[end]]++;
			end++;
		}
		// i ~ end 연속배열 추출
		cnt += end - i;
		visited[arr[i]]--;
		if (flag == 1 && arr[i] == temp_value) flag--;
	}
	cout << cnt;
}

int main() {

	input();
	solution();

	return 0;
}