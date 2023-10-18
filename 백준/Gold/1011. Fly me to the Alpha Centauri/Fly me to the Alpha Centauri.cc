#include<iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;

		int size = y - x;
		int num = 1;
		int cnt = 0;
		while (size != 0) {
			int next_size = size - (2 * num);
			if (next_size >= num + 1) {
				size -= (2 * num);
				num++;
				cnt += 2;
			}
			else {
				if (size >= num) {
					size -= num;
					cnt++;
				}
				else {
					num--;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}