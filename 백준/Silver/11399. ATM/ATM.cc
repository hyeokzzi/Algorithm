#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> arr;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}

void solution() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				int num = arr[i];
				arr.erase(arr.begin() + i);
				arr.insert(arr.begin() + j, num);
				break;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < N; j++) {
			arr[j] += arr[j - 1];
		}
	}
	cout << arr[N - 1];

}
int main() {
	input();
	solution();
	return 0;
}