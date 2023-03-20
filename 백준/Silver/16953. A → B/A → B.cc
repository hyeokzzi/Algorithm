#include<iostream>
#include<queue>
std::queue<long long> arr;
void bfs(long long B);
int flag = 0;
int main() {
	long long A, B;
	std::cin >> A >> B;
	arr.push(A);
	int t = 0;
	while (arr.size() != 0 && flag == 0 ) {
		t++;
		bfs(B);
	}
	if (flag != 0) {
		std::cout << t;
	}
	else {
		std::cout <<  "-1";
	}
	return 0;
}
void bfs(long long B) {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		// 확인
		long long num = arr.front();
		arr.pop();
		if (num == B) {
			flag = 1;
			return;
		}
		//숫자 추가
		long long mul_2 = num * 2;
		long long append_1 = (num * 10) + 1;

		if (mul_2 <= B) {
			arr.push(mul_2);
		}
		if (append_1 <= B) {
			arr.push(append_1);
		}
	}
}