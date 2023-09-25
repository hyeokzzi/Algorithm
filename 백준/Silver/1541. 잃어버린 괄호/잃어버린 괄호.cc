#include<iostream>
#include<string>
int num[51];
int num_index = 0;
int calculate[51];
int calculate_index = 0;


int main()
{
	char sentence[51];
	std::cin >> sentence;
	int index = 0; // 사이즈
	int make_num = 10000;
	int save_num = 0;
	while (sentence[index] != NULL) {
		if (sentence[index] != '+' && sentence[index] != '-') {
			
			save_num = save_num + (int(sentence[index] - '0') * make_num);
			make_num /= 10;
		}
		else
		{
			// 수 저장
			if (make_num == 0) {
				num[num_index] = save_num;
			}
			else {
				num[num_index] = save_num / (make_num * 10); // 숫자저장 ex) 55인경우 55000으로 저장되있음.

			}
			make_num = 10000; // 초기값으로 다시 
			num_index++;


			// 저장값 초기화
			save_num = 0;


			// 부호 저장
			if (sentence[index] == '+') {
				calculate[calculate_index] = 1;
				calculate_index++;
			}
			else {
				calculate[calculate_index] = -1;
				calculate_index++;
			}
		}
		index++;
	}
	// 마지막 수 저장
	
	if (make_num == 0) {
		num[num_index] = save_num;
	}
	else {
		num[num_index] = save_num / (make_num * 10); // 숫자저장 ex) 55인경우 55000으로 저장되있음.

	}
	make_num = 10000; // 초기값으로 다시 
	num_index++;

	// 가장 작은 수 찾기.
	int sum = num[0];
	int sum_index = 1;
	int cal_index = 0;
	int sub_num = 0;
	
	while (sum_index <= num_index) {
		if (calculate[cal_index] == -1) // 뺄셈이면
		{
			// 만약 뺄셈 기호를 만나면 뒤에 숫자를 다 더한 후에 빼줘야 가장 작은 수 완성.
			// 그러므로 계속 더해줘야함.
			sub_num += num[sum_index];
			sum_index++;
			cal_index++;

			// 뺄셈이나 수가 끝날 떄 까지 연산해야함.
			// 밑에 while문은 +가 나오면 실행하는 것.
			while (calculate[cal_index] != 0 && calculate[cal_index] != -1) {
				sub_num += num[sum_index];
				sum_index++;
				cal_index++;
			}
		}
		else {

			sum += num[sum_index];
			sum_index++;
			cal_index++;
		}
	}

	std::cout << sum - sub_num;
	return 0;
}