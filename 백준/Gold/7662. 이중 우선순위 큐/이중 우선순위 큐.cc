#include<iostream>
#include<map>
// 오름차순

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int test;
		std::cin >> test;
		std::multimap<int, int, std::greater<int>> pq;
		for (int k = 0; k < test; k++) {
			char word;
			int num;
			std::cin >> word >> num;

			if (word == 'I') {
				// k 는 순서? 사실 필요없음.
				pq.insert(std::make_pair(num, k));
			}
			else {
				if (pq.empty() != true) {
					if (num == -1) {
						std::multimap<int, int>::iterator iter = pq.end();
						iter--;
						pq.erase(iter);
					}
					else {
						std::multimap<int, int>::iterator iter = pq.begin();
						pq.erase(iter);
					}
				}
			}
		}

		if (pq.empty() == true) {
			std::cout << "EMPTY" << '\n';
		}
		else {
			std::multimap<int, int>::iterator iter = pq.end();
			iter--;
			std::cout << pq.begin()->first << " " << iter->first << '\n';
		}

	}



	return 0;
}