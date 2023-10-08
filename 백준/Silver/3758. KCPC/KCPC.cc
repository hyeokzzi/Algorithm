#include<iostream>
#include<vector>	
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int T, n, k, t, m;
typedef struct {
	int id, problem, score;
}node;
typedef struct {
	int id, total, submit, late;
}ans;
bool cmp(ans a, ans b) {
	if (a.total > b.total) return true;
	else if (a.total == b.total) {
		if (a.submit < b.submit) return true;
		else if (a.submit == b.submit) {
			if (a.late < b.late) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

vector<node> arr; // 순서 저장
vector<ans> vec;
int score[101][101]; // 팀당 점수 계산 y축 팀 / x축 점수
int late[101]; // 늦게 제출
int cnt[101];

void input() {
	arr.clear();
	vec.clear();
	memset(score, 0, sizeof(score));
	memset(late, 0, sizeof(score));
	memset(cnt, 0, sizeof(score));
	cin >> n >> k >> t >> m;	// 팀수 / 문제수 / 내팀 / 로그 수
	for (int i = 0; i < m; i++) {
		node temp;
		cin >> temp.id >> temp.problem >> temp.score;
		late[temp.id] = i;
		cnt[temp.id]++;
		arr.push_back(temp);
	}
}

void solution() {
	// 가장 높은 점수로 갱신
	for (int i = 0; i < m; i++) {
		node temp = arr[i];
		score[temp.id][temp.problem] = max(score[temp.id][temp.problem], temp.score);
	}
	// 합산 - 각 배열 0번지에 저장
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			score[i][0] += score[i][j];
		}
		vec.push_back({ i, score[i][0], cnt[i], late[i] });
	}
	sort(vec.begin(), vec.end(), cmp);
	int idx = 1;
	for (auto& e : vec) {
		if (e.id == t) {
			cout << idx << '\n';
			return;
		}
		idx++;
	}

}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		solution();
	}
	return 0;
}
