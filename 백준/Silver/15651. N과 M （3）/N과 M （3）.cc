#include<iostream>
using namespace std;
int N, M;
int arr[8];
void func(int level) {
	if (level == M) {
		for (int i = 0; i < level; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[level] = i;
		func(level + 1);
	}
}
int main() {
	cin >> N >> M;
	func(0);
	return 0;
}