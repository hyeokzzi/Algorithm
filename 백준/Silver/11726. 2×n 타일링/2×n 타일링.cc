//#include<iostream>
//
//int cnt = 0;
//int dp(int num) {
//	if (num == 0) return cnt = (cnt+1) % 10007;
//	if (num > 1) {
//		dp(num - 2);
//	}
//	if (num != 0) {
//		dp(num - 1);
//	}
//	return cnt%10007;
//}
//
//
//int main() {
//	int n;
//	std::cin >> n;
//	dp(n);
//	std::cout << cnt;
//
//	return 0;
//}

// bottom up
#include<iostream>

long arr[1001];

int dp(int t) {

	if (arr[t] != 0) return arr[t];
	if (t == 2) {
		return 2;
	}
	if (t == 1) {
		return 1;
	}

	return arr[t] = (dp(t-1) + dp(t - 2)) % 10007;
}

int main()
{
	int n;
	std::cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	std::cout << dp(n);

	return 0;
}