#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> arr[51];
vector<int> store;
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
				for (auto& e : arr[j]) {
					// 진실을 아는 사람과 같이 있을 때
					if (num == e) {
						for (auto& k : arr[j]) {
							if (pushed[k] == false) { 
								que.push(k);
								pushed[k] = true;
							}
						}
						break;
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
	
	/*
		거짓말을 할 수 있는 조건
		1. 아무도 이야기를 들은적이 없을 때
		2. 모두가 거짓말 이야기를 들었을 때
		3. 거짓이야기를 들은 사람과 이야기를 듣지 않은사람만 있을 때
		=> 진실을 아는 사람이 아예 없을 떄 가능
	*/

	// 진실을 듣는 경우의 수 처리 -> BFS?
	bfs(M);
	// 아닌 파티 찾기 -> 탐색
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