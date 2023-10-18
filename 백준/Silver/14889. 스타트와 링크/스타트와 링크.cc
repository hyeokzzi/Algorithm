#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int arr[21][21];
bool visited[21] = { false };
int N;
vector<int> team;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

int cal_score(vector<int> temp) {
	int sum = 0;
	int size = temp.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			sum += arr[temp[i]][temp[j]];
		}
	}
	return sum;
}

int min_score = 100000000;
void dfs(int idx) {
	if (idx == N && team.size() != N / 2) return;
	if (team.size() == N / 2) {
		vector<int> team_b;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) team_b.push_back(i);
		}

		int score_a = cal_score(team);
		int score_b = cal_score(team_b);
		min_score = min(min_score, abs(score_a - score_b));
		return;
	}
	for (int i = idx + 1; i <= N; i++) {
		if (!visited[i]) {
			team.push_back(i);
			visited[i] = true;
			dfs(i);
			team.pop_back();
			visited[i] = false;
		}
	}
}


void solution() {
	// 차이 최소
	// 같은 팀 인원 N/2명
	dfs(0);
	cout << min_score;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}