#include<iostream>
#include<queue>

using namespace std;
int N, M;
queue<int> que;
bool visited[100001];

void func(){
  bool checked = false;
  int cnt = 0;
  while(!que.empty()){
    int size = que.size();
    for(int i = 0; i < size; i++){
      int idx = que.front();
      que.pop();
      if(idx == M){
        checked = true;
        break;
      }
      if(idx * 2 <= 100000 && !visited[idx * 2]) {
        que.push(idx*2);
        visited[idx * 2] = true;
      }
      if(idx + 1 <= 100000 && !visited[idx + 1]){
        que.push(idx + 1);
        visited[idx + 1] = true;
      }
      if(idx - 1 >= 0 && !visited[idx - 1]){
        que.push(idx - 1);
        visited[idx - 1] = true;
      }
    }
    if(checked == true){
      cout << cnt;
      break;
    }
    cnt++;
  }
  return;
}


int main(int argc, char** argv)
{
  cin >> N >> M;
  que.push(N);
  visited[N] = true;
  func();
   return 0;
}