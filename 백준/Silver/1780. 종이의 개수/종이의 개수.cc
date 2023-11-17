#include<iostream>
using namespace std;
int N;
int arr[3000][3000];
int ans[4];
void input(){
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
}

void solution(int y, int x, int size){
  bool checked = false;
  for(int i = y; i < y + size; i++){
    for(int j = x; j < x + size; j++){
      if(arr[i][j] != arr[y][x]) {
        checked = true;
        break;
      }
    }
    if(checked) break;
  }

  if(checked){
    int t = size / 3;
    for(int i = y; i < y + size; i += t){
      for(int j = x; j < x + size; j += t){
        solution(i, j, t);
      }
    }
  }
  else{
    ans[(arr[y][x] + 1)]++;
  }
}

int main(int argc, char** argv)
{
  input();
  solution(0, 0, N);
  for(int i = 0; i < 3; i++){
    cout << ans[i] << '\n';
  }
   return 0;
}