#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> arr;

bool find(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void input() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (find(i)) arr.push_back(i);
	}
}

void solution() {
	
	int size = arr.size();
	int end = 0;
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		while (end < size && sum < N) {
			sum += arr[end];
			end++;
		}
		if (sum == N) cnt++;
		sum -= arr[i];
	}
	cout << cnt;

}

int main() {

	input();
	solution();

	return 0;
}