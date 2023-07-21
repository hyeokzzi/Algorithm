#include<iostream>
using namespace std;
int arr[20];
int main() {
	
	int N, K;
	cin >> N >> K;

	string s;
	cin >> s;

	int len = s.length();
	int flag = 0;
	int mul = 1;
	int idx = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '-') flag++;
		else if (s[i] == ',') {
			if (flag == 1) {
				arr[idx] = arr[idx] * (-1);
				flag = 0;
			}
			idx++;
		}
		else {
			arr[idx] = arr[idx] * 10 + (s[i] - '0');
		}
	}

	if (flag == 1) {
		arr[idx] = arr[idx] * (-1);
	}
	idx++;


	for (int i = 0; i < K; i++) {
		for (int j = 0; j < idx; j++) {
			arr[j] = arr[j + 1] - arr[j];
		}
		idx--;
	}

	for (int i = 0; i < idx; i++) {
		cout << arr[i];
		if (i != idx - 1) {
			cout << ",";
		}
	}



	return 0;
}