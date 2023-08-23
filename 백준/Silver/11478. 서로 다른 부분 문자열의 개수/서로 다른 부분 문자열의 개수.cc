#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;
unordered_set<string> arr;
string s;
int main() {
	cin >> s;
	int len = s.length();

	for (int i = 1; i <= len; i++){
		
		for (int start = 0; start <= len - i; start++) {
			string temp = "";
			for (int j = 0; j < i; j++) {
				temp += s[start + j];
			}
			arr.insert(temp);
		}
	}
	cout << arr.size();



	return 0;
}