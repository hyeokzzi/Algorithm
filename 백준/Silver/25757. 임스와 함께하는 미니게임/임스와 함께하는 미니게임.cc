#include<iostream>
#include<set>
using namespace std;

set<string> arr;
int main() {
	int N;
	char game;
	cin >> N >> game;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		arr.insert(s);
	}
	
	switch (game) {
	case 'Y':
		cout << arr.size() ;
		break;
	case 'F':
		cout << arr.size() / 2;
		break;
	case 'O' :
		cout << arr.size() / 3;
		break;
	}

	return 0;
}