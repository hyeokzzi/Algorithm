#include<iostream>
using namespace std;
double sum;

double return_num(string t) {
	double k = 0.0;
	if (t[0] == 'A') {
		k = 4.0;
	}
	else if (t[0] == 'B') {
		k = 3.0;
	}
	else if (t[0] == 'C') {
		k = 2.0;
	}
	else if (t[0] == 'D') {
		k = 1.0;
	}
	else {
		return 0.0;
	}
	if (t[1] == '+') return k + 0.5;
	return k;
}



int main() {
	int t = 20;
	int total_size = 0;
	while (t--) {
		string s, grade;
		double size;
		cin >> s >> size >> grade;
		if (grade[0] == 'P') continue;
		sum += size * return_num(grade);
		total_size += size;
	}
	cout << fixed;
	cout.precision(4);
	cout << sum / total_size;


	return 0;
}