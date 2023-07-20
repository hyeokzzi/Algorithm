#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

bool aaa(std::string a, std::string b)
{
	if (a.size() > b.size())
	{
		return false;
	}
	else if (a.size() == b.size())
	{
		if (a.compare(b) > 0)
		{
			return false;
		}
		return true;
	}
	return true;
}

int main()
{
	std::vector<std::string> arr;

	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++)
	{
		int cnt = 0;
		std::string t;
		std::cin >> t;
		for (auto e = arr.begin(); e < arr.end(); e++)
		{
			if (t.compare(*e) == 0)
			{
				cnt++; 
				break;
			}
		}
		if (cnt == 0)
		{
			arr.push_back(t);
		}
	}

	std::sort(arr.begin(), arr.end(),aaa);

	for (auto& e : arr)
	{
		std::cout << e << '\n';
	}
}