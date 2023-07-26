#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
queue<int> que;
vector<int> vec;
void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		que.push(num);
	}
}

void solution() {
	int cnt = 1;
	while (1) {
		if (!que.empty() && que.front() == cnt) {
			cnt++;
			que.pop();
		}
		else {
			if (!vec.empty() && vec.back() == cnt)
			{
				cnt++;
				vec.pop_back();
			}
			else {
				vec.push_back(que.front());
				que.pop();
			}
		}
		
		if (que.empty() && vec.empty()) {
			cout << "Nice";
			return;
		}
		if (que.empty() && vec.back() != cnt) break;
	}
	cout << "Sad";
}


int main() {
	input();
	solution();

	return 0;
}

