#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<pair<string, int>>> arr;
int N, M;
void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int level;
		string name;
		cin >> level >> name;
		int flag = 0;
		for (auto& e : arr) {
			int l = e.front().second;
			if (level >= l - 10 && level <= l + 10 && e.size() < M) {
				e.push_back({ name, level });
				flag = 1;
				break;
			}
		}
		// 들어가지 못한경우 방 생성
		if (flag == 0) {
			vector<pair<string, int>>temp;
			temp.push_back({ name,level });
			arr.push_back(temp);
		}
	}
}

void check() {
	for (auto& e : arr) {
		if (e.size() == M) {
			cout << "Started!" << '\n';
		}
		else {
			cout << "Waiting!" << '\n';
		}
		sort(e.begin(), e.end());
		for (auto& k : e) {
			cout << k.second << " " << k.first << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	check();
	return 0;
}