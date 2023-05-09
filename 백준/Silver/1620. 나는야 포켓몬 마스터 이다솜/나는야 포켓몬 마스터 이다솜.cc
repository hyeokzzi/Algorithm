#include<iostream>
#include<string>
#include<map>
#include<cstdlib>

std::map<std::string, int> arr;
std::map<int, std::string> arr_num;

int main()
{

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		std::string t;
		std::cin >> t;
		arr.insert({ t,i });
		arr_num.insert({ i,t });
	}

	for (int i = 0; i < M; i++)
	{
		std::string t;
		std::cin >> t;
		if (t[0] < 'A')
		{
			int num = atoi(t.c_str());
			auto a = arr_num.find(num);
			std::cout << a->second << '\n';
		}
		else
		{
			auto a = arr.find(t);
			std::cout << a->second << '\n';
		}
	}

	return 0;
}