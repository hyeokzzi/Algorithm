#include<iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	int ans = 0;
	// 세로가 1인 경우
	if (N == 2) {
		cout << min(4, (M + 1) / 2);
 	}
	else if (N < 2) {
		cout << 1;
	}
	// 세로가 2이상
	else {
		// 가로가 6 이하 -> 4개 이하
		if (M <= 6) {
			cout << min(4, M);
		}
		// 6 이상 --> 무조건 1개씩은 일단 가능 ( 0, 6 )
		else {
			cout << 4 + (M - 6);
		}
	}


	return 0;
}