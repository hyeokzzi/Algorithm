#include<iostream>
#include<vector>
using namespace std;
char arr[10];
int N;
vector<int> vec1;
vector<int> vec2;
bool visited[10] = { false };
bool checked = false;

void func_a(int num, int idx) {
	if (checked == true) return;
	if (idx == N) {
		checked = true;;
	}
	if (arr[idx] == '>') {
		for (int i = num - 1; i >= 0; i--) {
			if (visited[i]) continue;
			visited[i] = true;
			vec1.push_back(i);
			func_a(i, idx + 1);
			if (checked == true) return;
			vec1.pop_back();
			visited[i] = false;
		}
	}
	else {
		for (int i = 9; i > num; i--) {
			if (visited[i]) continue;
			visited[i] = true;
			vec1.push_back(i);
			func_a(i, idx + 1);
			if (checked == true) return;
			vec1.pop_back();
			visited[i] = false;
		}
	}
}
void func_b(int num, int idx) {
	if (checked == true) return;
	if (idx == N) {
		checked = true;
		return;
	}
	if (arr[idx] == '>') {
		for (int i = 0; i < num; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			vec2.push_back(i);
			func_b(i, idx + 1);
			if (checked == true) return;
			vec2.pop_back();
			visited[i] = false;
		}
	}
	else {
		for (int i = num + 1; i <= 9; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			vec2.push_back(i);
			func_b(i, idx + 1);
			if (checked == true) return;
			vec2.pop_back();
			visited[i] = false;
		}
	}
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	// 최댓값찾기
	for (int i = 9; i >= 0; i--) {
		visited[i] = true;
		vec1.push_back(i);
		func_a(i, 0);
		if (checked == true) break;
		vec1.pop_back();
		visited[i] = false;
	}

	checked = false;
	for (int i = 0; i <= 9; i++) visited[i] = false;
	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		vec2.push_back(i);
		func_b(i, 0);
		if (checked == true) break;
		vec2.pop_back();
		visited[i] = false;
	}
	for (auto& e : vec1) {
		cout << e;
	}
	cout << '\n';
	for (auto& e : vec2) {
		cout << e;
	}


	return 0;
}