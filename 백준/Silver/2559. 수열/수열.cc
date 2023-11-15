#include<iostream>
using namespace std;
int arr[100001];
int N, K;

void input(){
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
}
void solution(){
  int st = 0;
  int sum = 0;
  for(int i = 0; i < K; i++) sum += arr[i];
  int ans = sum;
  for(int i = K; i < N; i++){
    sum -= arr[i - K];
    sum += arr[i];
    ans = max(sum, ans);
  }
  cout << ans;
}



int main(int argc, char** argv)
{
  input();
  solution();
   return 0;
}