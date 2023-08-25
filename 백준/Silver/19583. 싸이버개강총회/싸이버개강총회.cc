#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;
unordered_set<string> uset;
int arr[3];
int timetonum(string s) {
	int t = 1000;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		if (i == 2) continue;
		sum += t * (s[i]-'0');
		t /= 10;
	}
	return sum;

}


int main() {
	// 시간입력
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		arr[i] = timetonum(s);
	}

	// 이후 채팅로그 입력
	int cnt = 0;
	string time, ID;
	while (cin >> time >> ID) {
		int t = timetonum(time);
		if (t <= arr[0]) {
			uset.insert(ID);
		}
		else if (t >= arr[1] && t <= arr[2]) {
			if (uset.find(ID) != uset.end()) {
				cnt++;
				uset.erase(ID);
			}
		}
	}

	cout << cnt;
	return 0;
}