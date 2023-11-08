#include<iostream>
#include<vector>
using namespace std;
int N;
int visited[1000] = { 0 };
int main() {
	cin >> N;
	for (int t = 0; t < N; t++) {
		string num;
		int strike, ball;
		cin >> num >> strike >> ball;

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (i == j) continue;
				for (int k = 1; k <= 9; k++) {
					if (i == k || j == k) continue;
					int cnt_s = 0;
					int cnt_b = 0;
					if (num[0] - '0' == i) cnt_s++;
					else if (num[0] - '0' == j || num[0] - '0' == k) cnt_b++;
	
					if (num[1] - '0' == j) cnt_s++;
					else if (num[1] - '0' == i || num[1] - '0' == k) cnt_b++;

					if (num[2] - '0' == k) cnt_s++;
					else if (num[2] - '0' == j || num[2] - '0' == i) cnt_b++;
					int sum = i * 100 + j * 10 + k;
					if (cnt_s == strike && cnt_b == ball && visited[sum] != -1) visited[sum]++;
					else visited[sum] = -1;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 100; i <= 999; i++) {
		if (visited[i] == N) cnt++;
	}
	cout << cnt;

	return 0;
}