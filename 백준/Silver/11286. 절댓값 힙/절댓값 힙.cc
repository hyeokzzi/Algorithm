#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) return true;
		else if(abs(a) < abs(b))return false;
		else {
			if (a > b) return true;
			else return false;
		}
	}
};
priority_queue<int, vector<int>, cmp> que;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			// 출력 -> pop
			if (que.empty()) {
				cout << "0" << '\n';
			}
			else {
				cout << que.top() << '\n';
				que.pop();
			}
		}
		else {
			// push
			que.push(num);
		}
	}

	return 0;
}