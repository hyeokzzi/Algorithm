#include<iostream>
#include<vector>
using namespace std;
int arr[51][51] = { 0, };
int visit[13] = { 0, };
vector<int> stack;

typedef struct node {
	int x;
	int y;
}node;
node shop[13];

int min_num = 1000000;
void func(int current_num, int visit_count, int shop_count, int N, int M) {
	if (visit_count == 0) {
		// 확인하는 매장 번호를 추출
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					int min_distance = 10000000;
					for (auto& e : stack) {
						int distance = abs(i - shop[e].x) + abs(j - shop[e].y);
						if (min_distance > distance) min_distance = distance;
					}
					sum += min_distance;
					if (sum >= min_num) return;
				}
			}
		}
		if (sum < min_num) min_num = sum;
		return;
	}
	
	for (int i = current_num + 1; i < shop_count; i++) {
		if (visit[i] == 0) {
			stack.push_back(i);
			visit[i] = 1;
			func(i,visit_count - 1, shop_count, N, M);
			visit[i] = 0;
			stack.pop_back();
		}
	}
}


int main(){
	int N, M, shop_count = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 2) {
				node temp;
				temp.x = i;
				temp.y = j;
				shop[shop_count] = temp;
				shop_count++;
			}
			else {
				arr[i][j] = num;
			}
		}
	}

	func(-1, M, shop_count, N, M);
	cout << min_num;


	return 0;
}