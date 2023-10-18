#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
vector<int> b;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;


	return 0;
}