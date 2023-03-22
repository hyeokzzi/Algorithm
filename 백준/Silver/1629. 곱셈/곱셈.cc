#include<iostream>
long long Divide_and_Conquer(long long A, long long B, long long C);
int main() {
	long long A, B, C;
	std::cin >> A >> B >> C;

	std::cout << Divide_and_Conquer(A, B, C);

	return 0;
}

long long Divide_and_Conquer(long long A, long long B, long long C) {
	if (B == 0) return 0;
	if (B == 1) return A % C;

	long long Divide = Divide_and_Conquer(A, B / 2, C) % C;
	if (B % 2 == 0) return Divide * Divide % C;
	else return Divide * Divide % C * A % C;

}