#include<iostream>
#include<string>
using namespace std;
int arr[1001][1001];
string a, b;
int main() {
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = b.size() - 1; j >= 0; j--) {
			if (a[i] == b[j]) {
				arr[i][j] = 1 + arr[i + 1][j + 1];
			}
			else {
				int one = arr[i + 1][j];
				int two = arr[i][j + 1];
				arr[i][j] = max(one, two);
			}
		}
	}
	cout << arr[0][0];
	return 0;
}