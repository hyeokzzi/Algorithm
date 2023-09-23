#include<iostream>

int arr[1000000] = { 0, };
int arr_[1000000] = { 0, };
void swap(int a, int b)
{
	int save = arr[a];
	arr[a] = arr[b];
	arr[b] = save;
}

void heapsort( int cur_idx, int size)
{
	int leftidx = cur_idx * 2;
	int rightidx = leftidx + 1;

	int biggest = cur_idx;

	if (leftidx <= size && arr[leftidx] > arr[cur_idx])
	{
		biggest = leftidx;
	}
	if (rightidx <= size && arr[rightidx] > arr[biggest])
	{
		biggest = rightidx;
	}
	if (biggest == cur_idx)
	{
		return;
	}
	else
	{
		swap(biggest, cur_idx);
		heapsort(biggest,size);
	}

}

void heapify(int size)
{
	int t = size / 2;

	while (t >= 1)
	{
		heapsort(t, size);
		t--;
	}
}

int removeRoot(int size)
{
	int retValue = arr[1];
	
	arr[1] = arr[size];
	heapsort(1, size - 1);

	return retValue;
}

int main()
{
	int N, num;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> num;
		arr[i] = num;
	}
	heapify(N);
	int save = N;
	while (save > 0)
	{
		arr_[save] = removeRoot(save);
		save--;
	}

	for (int i = 1; i <= N; i++)
	{
		std::cout << arr_[i] << '\n';
	}

	return 0;
}