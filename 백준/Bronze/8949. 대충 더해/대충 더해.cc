#include<iostream>
using namespace std;
int main() {

	int arr1[8] = { 0, }, arr2[8] = { 0, };
	int num1, num2;
	cin >> num1 >> num2;

	int size1 = 0, size2 = 0;
	while (num1 != 0) {
		arr1[size1] = num1 % 10;
		num1 /= 10;
		size1++;
	}

	while (num2 != 0) {
		arr2[size2] = num2 % 10;
		num2 /= 10;
		size2++;
	}

	int idx = max(size1, size2);
	for (int i = idx - 1; i >= 0; i--) {
		cout << arr1[i] + arr2[i];
	}
	return 0;
}