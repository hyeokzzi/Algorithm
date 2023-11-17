#include<iostream>
using namespace std;
int N,arr[1000001];

void input(){
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }
}
void solution(){
  int st = 1;
  int en = 2;
  while(en <= N){
    while(en <= N && arr[st] == arr[en]) en++;
    while(st < en && en <= N){
      arr[st++] = en;
    }
  }
  for(int i = 1; i<= N; i++){
    if(i >= st) cout << "-1 ";
    else cout << arr[i] << " ";
  }
}

int main(int argc, char** argv)
{
  input();
  solution();

   return 0;
}