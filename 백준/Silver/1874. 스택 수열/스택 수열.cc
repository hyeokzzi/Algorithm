#include<iostream>

int arr[100002] = { 0, };

int stack[100002] = { 0, };

int print[10000001] = { 0, };


int main()
{
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}
	int num; // 입력되는 숫자
	int last_num = 0;
	int print_idx = 0;
	int pop_cnt = N;
	int flag = 0;
	while (pop_cnt != 0)
	{
		std::cin >> num;
	
		if (flag == 0)
		{
			if (num >= last_num)
			{
				for (int i = last_num; i <= num; i++)
				{
					if (arr[i] != 0)
					{
						stack[i] = arr[i]; // stack 처럼 숫자를 1부터 쌓아가는중
						last_num = stack[i]; // 들어간 숫자의 마지막 숫자를 의미함.
						arr[i] = 0; // arr에서 0은 숫자가 이미 들어간것을 의미함.

						//push가 완료되었기 때문에 print배열에 push를 의미하는 1 넣기
						print[print_idx] = 1;
						print_idx++;
					}
				}
				stack[last_num] = 0;
				pop_cnt--;
				print[print_idx] = -1;
				print_idx++;
				while (stack[last_num] == 0 && last_num > 0)
				{
					last_num--;
				}
			}
			else if (num < last_num) // 이미 있는 숫자가 버려지므로 성립 x
			{
				flag++;
				pop_cnt--;
			}
		}
		else
		{
			pop_cnt--;
		}


	}

	if (flag > 0)
	{
		std::cout << "NO" << '\n';
		return 0;
	}
	for (int i = 0; i < print_idx; i++)
	{
		if (print[i] == 1)
		{
			std::cout << "+" << '\n';
		}
		else if (print[i] == -1)
		{
			std::cout << "-" << '\n';
		}
	}


	return 0;
}
