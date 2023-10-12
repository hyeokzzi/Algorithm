#include<iostream>
using namespace std;
string arr[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
int main() {
	string s;
	cin >> s;
	
	int idx = 0;
	int len = s.length();
	int ans = 0;
	while (idx < len) {
		int temp_idx = idx;
		for (int i = 0; i < 8; i++) {
			if (s[idx] == arr[i][0]) {
				int temp = arr[i].length();
				int cnt = 0;
				for (int j = 0; j < temp; j++) {
					if (s[idx + j] == arr[i][j]) cnt++;
				}
				if (cnt == temp) {
					ans++;
					idx += temp;
					break;
				}
			}
		}
		if (temp_idx == idx) {
			ans++;
			idx++;
		}
	}
	cout << ans;
	return 0;
}