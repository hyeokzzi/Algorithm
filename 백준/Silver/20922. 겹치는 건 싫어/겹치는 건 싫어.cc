#include<iostream>
using namespace std;
int N, K;
int arr[200001];
int visited[100001] = { 0, };

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solution() {

	int end = 0;
	int flag = 0;
	int max_dist = 0;
	for (int i = 0; i < N; i++) {
		while (end < N && flag == 0) {
			visited[arr[end]]++;
			if (visited[arr[end]] > K) flag++;
			if(flag == 0) max_dist = max(max_dist, end - i + 1);
			end++;
		}

		visited[arr[i]]--;
		if (visited[arr[i]] == K) flag--;
	}
	cout << max_dist;
}

int main() {

	input();
	solution();

	return 0;
}