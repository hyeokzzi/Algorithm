#include<iostream>
using namespace std;
typedef struct node {
	int one = 0;
	int two = 0;
	int three = 0;
	bool possible = false;
}node;
node arr[17][17];
int main() {


	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j].possible;
		}
	}
	node temp;
	temp.one = 1;
	arr[1][2] = temp;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (arr[y][x].one != 0) {
				if (arr[y][x + 1].possible == 0 && arr[y + 1][x + 1].possible == 0 && arr[y + 1][x].possible == 0) {
					arr[y + 1][x + 1].two += arr[y][x].one;
				}
				if (arr[y][x + 1].possible == 0) {
					arr[y][x + 1].one += arr[y][x].one;
				}
			}
			if (arr[y][x].two != 0) {
				if (arr[y][x + 1].possible == 0) {
					arr[y][x + 1].one += arr[y][x].two;
				}
				if (arr[y][x + 1].possible == 0 && arr[y + 1][x + 1].possible == 0 && arr[y + 1][x].possible == 0) {
					arr[y + 1][x + 1].two += arr[y][x].two;
				}
				if (arr[y + 1][x].possible == 0) {
					arr[y + 1][x].three += arr[y][x].two;
				}
			}
			if (arr[y][x].three != 0) {
				if (arr[y][x + 1].possible == 0 && arr[y + 1][x + 1].possible == 0 && arr[y + 1][x].possible == 0) {
					arr[y + 1][x + 1].two += arr[y][x].three;
				}

				if (arr[y + 1][x].possible == 0) {
					arr[y + 1][x].three += arr[y][x].three;
				}
			}

		}
	}


	cout << arr[N][N].one + arr[N][N].two + arr[N][N].three;
	return 0;
}