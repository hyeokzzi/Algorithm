#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int N;
		cin >> N;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int cx, cy, d;
			cin >> cx >> cy >> d;

			int dist1 = pow(cx - x1, 2) + pow(cy - y1, 2);
			int dist2 = pow(cx - x2, 2) + pow(cy - y2, 2);
			int r = pow(d, 2);
			if (dist1 < r && dist2 < r) {

			}
			else {
				if (dist1 < r) cnt++;
				if (dist2 < r) cnt++;

			}


		}
		cout << cnt << '\n';
	}



	return 0;
}