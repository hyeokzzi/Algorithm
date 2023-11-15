#include<iostream>
using namespace std;
int N, S;
int arr[100001];

void input(){
  cin >> N >> S;
  for(int i =0; i < N; i++){
    cin >> arr[i];
  }
}

void solution(){
  int st = 0;
  int en = 1;
  int sum = arr[st];
  int len = 1000000;
  while(st < N){
    while(en < N && sum < S){
      sum+= arr[en];
      en++;
    }
    if( sum >= S ) len = min(len, en - st);
    sum -= arr[st];
    st++;
  }
  if(len > 100000) cout << "0";
  else cout << len;
}

int main(int argc, char** argv)
{
  input();
  solution();

   return 0;
}