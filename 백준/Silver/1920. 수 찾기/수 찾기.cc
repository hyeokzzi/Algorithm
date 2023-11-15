#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001], N, M;

void input(){
  cin >> N;
  for(int i = 0; i < N; i++) cin >> arr[i];
}
bool func(int t){
  int st = 0, en = N - 1;
  int mid = (st + en) / 2;
  bool checked = false;
  while(st < en){
    if(arr[mid] < t){
      st = mid + 1;
    }
    else if(arr[mid] >= t){
      en = mid;
    }
    mid = (st + en) / 2;
  }
  if(arr[en] == t) return true;
  else return false;
}

void solution(){
  sort(arr, arr+N);
  cin >> M;
  for(int i = 0; i < M; i++){
    int value;
    cin >> value;
    cout << func(value) << '\n';
  }
}

int main(int argc, char** argv)
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  input();
  solution();
   return 0;
}