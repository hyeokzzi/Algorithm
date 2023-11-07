#include<iostream>
using namespace std;
int main() {
	long long x, y;
	cin >> x >> y;


	long long z = y * 100 / x;
	int top = 1000000000;
	int bot = 1;
	int mid = (top + bot) / 2;
	if (z > 98) cout << "-1";
	else {
		long long cnt = 1;
		while (1) {
			if (z != ((y + cnt) * 100) / (x + cnt)) {
				top = cnt;
				break;
			}
			cnt *= 10;
		}

		while (top > bot) {
			if (z != ((y + mid) * 100 / (x + mid))) {
				top = mid;
			}
			else {
				bot = mid + 1;
			}
			mid = (top + bot) / 2;
		}
		cout << top;
	}




	return 0;
}