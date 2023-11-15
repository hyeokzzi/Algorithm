#include<iostream>
using namespace std;
int arr1[1000001], arr2[1000001];
int N, M;
int ans[2000001];
void input(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> arr1[i];
  }
  for(int i = 0; i < M; i++){
    cin >> arr2[i];
  }
}
void solution(){
  int st1 = 0, st2 = 0, idx = 0;
  while(st1 < N && st2 < M){
    int num = 0;
    if(arr1[st1] > arr2[st2]) num = arr2[st2++];
    else num = arr1[st1++];
    ans[idx++] = num;
  }
  while(st1 < N) ans[idx++] = arr1[st1++];
  while(st2 < M) ans[idx++] = arr2[st2++];
  for(int i = 0; i < N + M; i++) cout << ans[i] << " ";
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