#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	// 5 10 15 20
	int dist[4] = { 5, 10, 15, 20 };
	int idx = 0;
	while (1) {
		if (N - dist[(idx / 2) % 4] < 0) {
			// 가는거
			if (idx % 2 == 0) {
				int level = 0;
				if (N == 0) cout << level;
				else {
					level++;
					while (N - 5 > 0) {
						level++;
						N -= 5;
					}
					cout << level;
				}
			}
			else {
				int level = (idx / 2) % 4 + 1;
				while (N - 5 >= 0) {
					level--;
					N -= 5;
				}
				cout << level;
			}
			break;
		}	
		N -= dist[(idx / 2) % 4];
		idx++;
		
	}



	return 0;
}