# [Gold IV] 타일 채우기 - 2133 

[문제 링크](https://www.acmicpc.net/problem/2133) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 문제 설명

<p>3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.</p>

### 입력 

 <p>첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.</p>

### 출력 

 <p>첫째 줄에 경우의 수를 출력한다.</p>


# 문제 풀이 1 - 처음 풀이

```csharp
#include<iostream>
using namespace std;
int dp(int N) {
	if (N % 2 == 1) return 0;
	if (N >= 4) {
		int sum = 2;
		for (int i = N; i >= 4; i -= 2) {
			sum += 2 * dp(i - 4);
		}
		sum += 3 * dp(N - 2);
		return sum;
	}
	if (N == 2) return 3;
	if (N == 0) return 0;
	
}

int main() {
	int N;
	cin >> N;
	cout << dp(N);
	return 0;
}
```

- 재귀 함수를 이용하여 문제 해결하였으나 dp의 특성인 저장한 값을 이용한다는 개념이 누락되어 새로 풀이

# 문제 풀이 2 - dp 풀이

```csharp
#include<iostream>
using namespace std;
int dp[31];
int main() {
	int N;
	cin >> N;

	dp[2] = 3;
	dp[0] = 1;

	for (int i = 4; i <= N; i+=2) {
		for (int j = i; j > 0; j -= 2) {
			if (j != 2) {
				dp[i] += 2 * dp[i - j];
			}
			else if (j == 2) {
				dp[i] += dp[2] * dp[i - j];
			}
		}
	}
	cout << dp[N];
	return 0;
}
```
