#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[100001], N;

void input(){
  cin >> N;
  for(int i = 0; i < N; i++) cin >> arr[i];
}

void solution(){
  sort(arr, arr+N);
  int st = 0;
  int en = N-1;
  int sum = abs(arr[st] + arr[en]);
  int min_value = arr[st], max_value = arr[en];
  while(st < en){
    if(sum > abs(arr[st] + arr[en])){
      min_value = arr[st];
      max_value = arr[en];
      sum = abs(arr[st] + arr[en]);
    }

    if(arr[st] + arr[en] < 0) st++;
    else en--;
  }
  cout << min_value << " " << max_value;
  return;
}

int main(int argc, char** argv)
{
  input();
  solution();
  
   return 0;
}