#include<iostream>

int arr[10001] = { 0, };
// 가장 큰것의 길이를 가져옴. 가지고있는 선의 갯수도 받아옴
long long find_max_length(long long t, long long k, long long n)
{
	long long num = t;
	long long top = t;
	long long bottom = 0;
	long long sum = 0;

	long long max_length = 0;

	while (1)
	{
		sum = 0;
		// 모든 선을 num의 길이로 잘라본 후 만들어지는 선의 갯수를 파악
		for (long long i = 0; i < k; i++)
		{
			sum += arr[i] / num;
		}
		if (num == top && sum == n) return top;
		if (sum >= n && (top -num == 1) )return num;
		if (sum < n) // 합이 작으므로 길이는 작아져야 함.
		{
			top = num;
			num = (num + bottom) / 2;
		}
		else if (sum >= n) // 합이 더 크므로 길이는 더 길어져야 함.
		{
			bottom = num;
			num = (top + num) / 2;
		}
	}
}

int main()
{
	int N, K;
	std::cin >> K >> N;
	// K = 가지고 있는 선의 갯수
	// N = K개의 선으로 만들어야하는 선 갯수
	long long max = 0;
	for (long long i = 0; i < K; i++)
	{
		long long t;
		std::cin >> t;
		arr[i] = t;
		if (t > max)
		{
			max = t;
		}
	}
	std::cout << find_max_length(max, K, N);


	return 0;
}