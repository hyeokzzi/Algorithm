#include<iostream>
using namespace std;
char tree[100000001];
int alphabet[26] = { 0, };


void front_print(int idx) {
	cout << tree[idx];
	if (tree[idx * 2] != '.') front_print(idx * 2);
	if (tree[idx * 2 + 1] != '.') front_print(idx * 2 + 1);
}
void middle_print(int idx) {
	if (tree[idx * 2] != '.') middle_print(idx * 2);
	cout << tree[idx];
	if (tree[idx * 2 + 1] != '.') middle_print(idx * 2 + 1);
}
void back_print(int idx) {
	if (tree[idx * 2] != '.') back_print(idx * 2);
	if (tree[idx * 2 + 1] != '.') back_print(idx * 2 + 1);
	cout << tree[idx];
}

int visit[26] = { 0, };
int main() {
	int N;
	cin >> N;
	alphabet[0] = 1;
	tree[1] = 'A';
	for (int i = 0; i < N; i++) {
		char head, left, right;
		cin >> head >> left >> right;
		int root_num = alphabet[head - 'A'];
		if (left != '.') {
			alphabet[left - 'A'] = root_num * 2;
		}
		tree[root_num * 2] = left;
		
		if (right != '.') {
			alphabet[right - 'A'] = root_num * 2 + 1;
		}
		tree[root_num * 2 + 1] = right;
	}

	// 전위 순회 - 루트 왼쪽 오른쪽
	front_print(1);
	cout << '\n';
	// 중위 순회 - 왼쪽 루트 오른쪽
	middle_print(1);
	cout << '\n';
	// 후위 순회 - 왼쪽 오른쪽 루트
	back_print(1);


	return 0;
}