#include<iostream>
using namespace std;
int main() {
	int a, b;
	int c, d;
	cin >> a >> b >> c >> d;


	int numerator = a * d + b * c;
	int denominator = b * d;

	int max_num = max(numerator, denominator);
	int min_num = min(numerator, denominator);
	while (max_num % min_num != 0) {
		while (max_num - min_num > 0) {
			max_num -= min_num;
		}
		int temp = max_num;
		max_num = min_num;
		min_num = temp;
	}

	cout << numerator / min_num << " " << denominator / min_num;

	return 0;
}