#include<iostream>
#include<vector>
using namespace std;
long long flag, N, k;

bool visited[21] = { false };
int arr[21];

long long fact(int n) {
	long long sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	return sum;
}

long long find_k(int idx) {
	if (idx == N) return 0;
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[idx] == i) {
			visited[i] = true;
			return sum += find_k(idx + 1);
			
		}
		else {
			if (!visited[i]) sum += fact(N - idx);
 		}
	}
	return sum;
}

long long total = 0;
void find_arr(int idx) {
	if (idx == N + 1) return;
	long long size = fact(N - idx);
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		if (total + size >= k) {
			cout << i << " ";
			visited[i] = true;
			find_arr(idx + 1);
			return;
		}
		else {
			total += size;
		}
	}
}


int main() {

	cin >> N >> flag;
	if (flag == 1) {
		cin >> k;
		find_arr(1);
	}
	else {
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		cout << find_k(1) + 1;
	}
	return 0;
}