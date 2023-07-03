#include<iostream>
using namespace std;
int main() {

	int A, B, C;
	cin >> A >> B >> C;
	int pay[4] = { 0,A,B,C };
	int arr[101] = { 0, };
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			arr[j]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < 101; i++) {
		sum += arr[i] * pay[arr[i]];
	}
	cout << sum;
	return 0;
}