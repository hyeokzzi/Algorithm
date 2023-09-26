#include<iostream>
#include<cmath>
using namespace std;
bool arr[10000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	long long a, b;
	cin >> a >> b;

	long en = sqrt(b);

	long long cnt = 0;
	for (int i = 2; i * i <= en; i++) {
		if (arr[i] == true) continue;
		// 소수의 배수 지우기
		for (int j = i + i; j <= en; j += i) {
			arr[j] = true;
		}
	}

	for (int i = 2; i <= en; i++) {
		if (arr[i] == true) continue;
		long long num = i;
		while ((double)num <= (double)b / (double)i) {
			if ((double)num >= (double)a / (double)i) cnt++;
			num *= i;
		}
	}


	cout << cnt;


	return 0;
}