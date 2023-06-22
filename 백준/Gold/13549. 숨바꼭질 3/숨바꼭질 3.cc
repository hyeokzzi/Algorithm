#include<iostream>
#include<queue>
using namespace std;
// <비용, 위치>에 대한 우선순위 큐
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> arr;
int visit[100001] = { 0, };

int main() {
	int N, K;
	cin >> N >> K; 
	int min_cost = 100001;
	arr.push(make_pair(0, N));
	while (arr.empty() != true) {
		int cost = arr.top().first;
		int position = arr.top().second;
		visit[position] = 1;
		arr.pop();
		if (position == K) {
			min_cost = min(cost, min_cost);
			break;
		}

		if ((position - 1) >= 0 && visit[position - 1] == 0) {
			arr.push(make_pair(cost + 1, position - 1));
		}
		if ((position + 1) <= 100000 && visit[position + 1] == 0) {
			arr.push(make_pair(cost + 1, position + 1));
		}
		if ((position * 2) <= 100000 && visit[position * 2] == 0) {
			arr.push(make_pair(cost, position * 2));
		}
	}
	cout << min_cost;

	return 0;
}