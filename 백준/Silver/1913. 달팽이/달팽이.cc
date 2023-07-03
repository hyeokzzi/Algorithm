#include<iostream>
using namespace std;
int arr[1000][1000] = { 0, };
int main() {

	int N;
	cin >> N;
	int num;
	cin >> num;


	// 1 1 2 2 3 3 4 4 정보 + 방향정보 ( 시계방향 )
	int center = N / 2 + 1;
	int direction = 0;  // 0 : 위 / 1 : 우 / 2 : 아래 / 3 : 좌
	int size = 1; // 이동 거리

	// 시작 위치정보
	int start_x = center;
	int start_y = center;

	int cnt = 1;
	arr[start_y][start_x] = cnt;
	cnt++;
	int flag = 0;
	while (cnt <= (N*N)) {

		for (int j = 0; j < size; j++) {
			// 탈출 조건
			if (cnt > (N*N)) break; 
			if (direction % 4 == 0) {
				arr[--start_y][start_x] = cnt;
			}
			else if (direction % 4 == 1) {
				arr[start_y][++start_x] = cnt;
			}
			else if (direction % 4 == 2) {
				arr[++start_y][start_x] = cnt;
			}
			else {
				arr[start_y][--start_x] = cnt;
			}
			cnt++;
		}
		flag++;
		if (flag % 2 == 0) size++;
		direction++;
	}

	int x = 0;
	int y = 0;

	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++) {
			if (arr[i][j] == num) {
				y = i;
				x = j;
			}
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << y << " " << x;


	return 0;
}