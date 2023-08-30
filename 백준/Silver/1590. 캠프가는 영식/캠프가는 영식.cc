#include<iostream>
#include<set>
using namespace std;
set<int> arr;
int main() {

	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int S, I, C;
		cin >> S >> I >> C;
		
		for (int j = 0; j < C; j++) {
			arr.insert(S + (j * I));
		}
	}
	
	for (auto& e : arr) {
		if (e - T >= 0) {
			cout << e - T;
			return 0;
		}
	}
	cout << "-1";

	return 0;
}