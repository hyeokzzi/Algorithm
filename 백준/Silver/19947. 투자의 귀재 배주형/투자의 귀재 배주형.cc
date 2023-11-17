#include<iostream>
using namespace std;
long long dp[11];
int main(int argc, char** argv)
{
  long long N, M;
  cin >> N >> M;
  // 5 10
  dp[0] = N;
  for(int i = 1; i <= M; i++){
    dp[i] = (dp[i-1] * 105 / 100);
    if(i >= 3){
      dp[i] = max(dp[i], dp[i-3] * 120 / 100);
    }
    if(i >= 5){
      dp[i] = max(dp[i], dp[i-5] * 135 / 100);
    }
  }
  cout << dp[M];
   return 0;
}