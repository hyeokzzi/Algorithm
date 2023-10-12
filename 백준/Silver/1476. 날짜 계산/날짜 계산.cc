#include<iostream>
using namespace std;
int arr[29];
int main() {
	int e, s, m;
	cin >> e >> s >> m;

	int idx = 1;
	while (1) {
		int cnt = 0;
		if ((e == 15 && idx % 15 == 0) || idx % 15 == e) cnt++;
		if ((s == 28 && idx % 28 == 0) || idx % 28 == s) cnt++;
		if ((m == 19 && idx % 19 == 0) || idx % 19 == m) cnt++;
		
		if (cnt == 3) {
			cout << idx;
			break;
		}
		idx++;
	}
	return 0;
}