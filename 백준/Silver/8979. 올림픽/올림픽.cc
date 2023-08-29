#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct {
	int country;
	int g;
	int s;
	int b;
} node;

bool cmp(node a, node b) {
	if (a.g < b.g) return true;
	else {
		if (a.g == b.g) {
			if (a.s < b.s) return true;
			else {
				if (a.s == b.s) {
					if (a.b < b.b) return true;
				}
			}
		}
	}
	return false;
}
vector<node> arr;
int main() {
	int N, K;
	cin >> N >> K;
	node ans;
	for (int i = 0; i < N; i++) {
		node temp;
		cin >> temp.country >> temp.g >> temp.s >> temp.b;
		if (temp.country == K) ans = temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), cmp);
	int cnt = 1;
	for (auto& e : arr) {
		if (e.g == ans.g && e.s == ans.s && e.b == ans.b) break;
		cnt++;
	}
	cout << cnt;
	return 0;
}