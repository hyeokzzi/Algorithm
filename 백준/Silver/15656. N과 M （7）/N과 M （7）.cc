#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vec;
int arr[8];
int N, M;
void func(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for(int i = 0; i < N;i++){
		arr[level] = vec[i];
		func(level + 1);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	func(0);

	return 0;
}