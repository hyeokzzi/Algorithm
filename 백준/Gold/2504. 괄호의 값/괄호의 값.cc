#include<iostream>
#include<vector>
using namespace std;
vector<int> add_arr;
string s;
pair<int, int> func_a(int);
pair<int, int> func_b(int);
// (
pair<int,int> func_a(int idx) {
	int sum = 0;
	while (1) {
		pair<int, int> temp;
		// 자신 함수의 종료 조건 만남
		if (s[idx] == ')') {
			if (sum == 0) sum = 1;
			sum *= 2;
			temp = { sum, idx + 1 };
			return temp;
		}
		else {
			if (s[idx] == '(') {
				temp = func_a(idx + 1);
				if (temp.second == -1) return temp;
			}
			else if (s[idx] == '[') {
				temp = func_b(idx + 1);
				if (temp.second == -1) return temp;
			}
			// 있어서는 안되는 조건
			else {
				temp = { -1, -1 };
				return temp;
			}
			
		}
		idx = temp.second;
		sum += temp.first;
	}
}

// [
pair<int,int> func_b(int idx) {
	int sum = 0;
	while (1) {
		pair<int, int> temp;
		// 자신 함수의 종료 조건 만남
		if (s[idx] == ']') {
			if (sum == 0) sum = 1;
			sum *= 3;
			temp = { sum, idx + 1 };
			return temp;
		}
		else {
			if (s[idx] == '(') {
				temp = func_a(idx + 1);
				if (temp.second == -1) return temp;
			}
			else if (s[idx] == '[') {
				temp = func_b(idx + 1);
				if (temp.second == -1) return temp;
			}
			// 있어서는 안되는 조건
			else {
				temp = { -1, -1 };
				return temp;
			}

		}
		idx = temp.second;
		sum += temp.first;
	}
}


int main() {
	cin >> s;
	int idx = 0;
	int len = s.length();
	int sum = 0;
	while (len > idx) {

		if (idx == -1) {
			cout << "0";
			break;
		}

		pair<int, int> temp;
		if (s[idx] == '(') {
			temp = func_a(idx + 1);
		}
		else if (s[idx] == '[') {
			temp = func_b(idx + 1);
		}
		else {
			temp = { -1, -1 };
		}
		sum += temp.first;
		idx = temp.second;
	}
	if (idx != -1) {
		cout << sum;
	}

	return 0;
}