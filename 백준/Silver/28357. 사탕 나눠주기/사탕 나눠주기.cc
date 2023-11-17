#include<iostream>
#include<cmath>
using namespace std;
long long N, K;
long long arr[500001];

void input(){
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
}

void solution(){
  long long en = 1000000000000;
  long long st = 0;
  long long mid = (en + st) / 2;
  long long max_num = 0;
  while (st < en){
    long long sum = 0;
    for(int i = 0; i < N ;i++){
      if(mid < arr[i]) sum += (arr[i] - mid);
    }
    if(sum > K){
      st = mid + 1;
    }
    else{
      en = mid;
    }
    mid = (st + en) / 2;
  }
  cout << en ;
}

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  input();
  solution();
   return 0;
}