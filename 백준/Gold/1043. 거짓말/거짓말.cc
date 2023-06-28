#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> arr[51];
queue<int> que;
int visit[51] = { false, };
int pushed[51] = { false, };
void bfs(int M) {
	while (que.empty() == false) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int num = que.front();
			int flag = 0;
			que.pop();
			for (int j = 1; j <= M; j++) {
				// 있다.
				if (find(arr[j].begin(), arr[j].end(), num) != arr[j].end()) {
					for (auto& k : arr[j]) {
						if (pushed[k] == false) {
							que.push(k);
							pushed[k] = true;
						}
					}
				}
			}
		}

	}
}


int main() {
	int N, M;
	cin >> N >> M;
	int known_person, known_num;
	cin >> known_person;
	for (int i = 0; i < known_person; i++) {
		cin >> known_num;
		que.push(known_num);
		pushed[known_num] = true;
	}

	for (int i = 1; i <= M; i++) {
		int party_num, person;
		cin >> party_num;
		for (int j = 0; j < party_num; j++) {
			cin >> person;
			arr[i].push_back(person);
		}
	}
	
	bfs(M);
	int lie = 0;
	for (int i = 1; i <= M; i++) {
		int cnt = 0;
		for (auto& e : arr[i]) {
			if (pushed[e] == true) break;
			cnt++;
		}
		if (cnt == arr[i].size()) lie++;
	}
	cout << lie;


	return 0;
}