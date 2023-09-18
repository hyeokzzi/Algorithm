#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
unordered_map<char, int> save;

int N;
string word;
string arr[100];

void input() {
	cin >> N >> word;
	int len = word.length();
	for (int i = 0; i < len; i++) {
		if (save.find(word[i]) == save.end()) {
			save.insert({ word[i],1 });
		}
		else {
			save[word[i]]++;
		}
	}
	for(int i = 0; i < N-1;i++){
		cin >> arr[i];
	}
}
int cnt = 0;
void solution() {

	for (int i = 0; i < N - 1; i++) {
		int len = arr[i].length();
		unordered_map<char, int> temp = save;
		
		int char_flag = 0;
		int minus_flag = 0;
		int rest_flag = 0;

		for (int k = 0; k < len; k++) {
			// 다른문자 존재
			if (temp.find(arr[i][k]) == temp.end()) {
				char_flag++;
			}
			else {
				// 갯수 넘침
				if (temp[arr[i][k]] == 0) minus_flag++;
				else {
					temp[arr[i][k]]--;
				}
			}
		}
		// 갯수 부족
		for (auto& e : temp) {
			rest_flag += e.second;
		}
		if (char_flag + minus_flag + rest_flag == 0) cnt++;
		else {
			if (rest_flag == 1) {
				if (minus_flag + char_flag <= 1) cnt++;
			}
			else if (rest_flag == 0) {
				if (minus_flag + char_flag <= 1) cnt++;
			}
		}
	}
	cout << cnt;
}


int main() {
	input();
	solution();

	return 0;
}