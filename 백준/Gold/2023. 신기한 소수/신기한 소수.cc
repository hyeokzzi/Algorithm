#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> ans;
int N;

void dfs(int sum) {
	if (sum >= pow(10, N - 1)) {
		ans.push_back(sum);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		int num = sum;
		num = (num * 10) + i;
		int flag = 0;
		for (int j = 2; j <= sqrt(num); j++) {
			if(num % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) dfs(num);
	}
}


int main() {

	cin >> N;
	int arr[4] = { 2,3,5,7 };
	for (int i = 0; i <4; i++) {
		dfs(arr[i]);
	}
	for (auto& e : ans) {
		cout << e << '\n';
	}


	return 0;
}