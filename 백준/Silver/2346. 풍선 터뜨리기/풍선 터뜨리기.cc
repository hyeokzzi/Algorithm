#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N;
vector<int> vec;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
}

void solution() {
	int cnt = 0;
	int mov = 0;
	int idx = 0;
	int size = vec.size();
	while (cnt < size) {
		if (mov < 0) {
			for (int i = 0; i < abs(mov); i++) {
				if (idx == 0) idx = size;
				idx--;
				if (vec[idx] == 0) {
					while (vec[idx] == 0) {
						idx--;
						if (idx < 0) idx = size - 1;
					}
				}
			}
		}
		else{
			for (int i = 0; i < mov; i++) {
				if (idx == size - 1) idx = -1;
				idx++;
				if (vec[idx] == 0) {
					while (vec[idx] == 0) {
						idx++;
						if (idx == size) idx = 0;
					}
				}
			}
		}
		cout << idx + 1 << " ";
		mov = vec[idx];
		vec[idx] = 0;

		cnt++;
	}
}

int main() {
	input();
	solution();

	return 0;
}