#include<iostream>
using namespace std;
int main()
{
	int height;
	cin >> height;
	int save_height = height;
	int cnt_five = 0;
	int cnt_three = 0;
	
	int save_five_cnt = 0;
	int three_flag = 0;

	while (height != 0)
	{
		if (height % 3 == 0)
		{
			three_flag++;
			save_height = height;
			save_five_cnt = cnt_five;
		}

		if (height >= 5)
		{
			cnt_five++;
			height -= 5;
		}
		else
		{
			if (height - 3 < 0)
			{
				if (three_flag > 0)
				{
					cout << save_height / 3 + save_five_cnt;
					return 0;
				}
				cout << "-1";
				return 0;
			}
			cnt_three++;
			height -= 3;
		}
	}
	cout << cnt_five + cnt_three;
	return 0;
}