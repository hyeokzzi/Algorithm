#include<iostream>
using namespace std;
int find_char(char* name, int idx, char word) {
	int i = idx;
	int flag = 0;
	for (; name[i] != 0; i++) {
		if (name[i] == word) flag++;
		if (name[i] != word) break;
	}
	if (flag == 0) {
		return -1;
	}
	return i;
}


int main() {
	int N;
	cin >> N;
	char check[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	for (int i = 0; i < N; i++) {
		char name[210];
		cin >> name;

		// 첫번째 조건 - 첫글자 포함 확인
		int first_flag = 0;
		for (auto e : check) {
			if (name[0] == e) {
				first_flag = 1;
			}
		}
		//첫번째 탈출
		if (first_flag == 0) {
			cout << "Good" << '\n';
			continue;
		}

		// 두번째 조건 - AFC 확인
		int idx = 0;
		if (name[idx] != 'A') {
			idx = 1;
		}
		char arr[3] = { 'A', 'F', 'C' };
		for (int j = 0; j < 3; j++) {
			idx = find_char(name, idx, arr[j]);
			if (idx == -1) break;
		}
		if (idx == -1) {
			cout << "Good" << '\n';
			continue;
		}

		// name[idx] == a~f거나 name[idx] == 0이면 true
		int third_flag = 0;
		for (auto e : check) {
			if (e == name[idx]) {
				third_flag = 1;
				break;
			}
		}
		if ((third_flag == 1 && name[idx + 1] == 0) || name[idx] == 0) {
			cout << "Infected!" << '\n';
		}
		else {
			cout << "Good" << '\n';
		}

	}

	return 0;
}