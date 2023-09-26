#include<iostream>

#include<cmath>

int arr[1000002] = { 0, };

void pickPrimeNum(int start, int size)
{
	int front = start;
	int end = size;

	for (int i = front; i <= size; i++)
	{
		arr[i] = i;
	}


	for (int i = 2; i <= sqrt(size); i++)
	{
		if (i >= front && arr[i] == 0) continue;

		for (int j = i * i; j <= size; j += i)
		{
			arr[j] = 0;
		}
	}
	arr[1] = 0;
	for (int i = start; i <= size; i++)
	{
		if (arr[i] != 0)
		{
			std::cout << arr[i] << '\n';
		}
	}


}


int main()
{

	int N, M;
	std::cin >> N >> M;
	pickPrimeNum(N, M);

	return 0;
}