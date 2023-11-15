#include<iostream>
#include<queue>
using namespace std;
int N;
char arr[101][101];

bool visited[101][101];

void input(){
  cin >> N;
  for(int i = 1; i <= N; i++){
    string s;
    cin >> s;
    for(int j = 1; j<= N; j++){
      arr[i][j] = s[j - 1];
    }
  }
}
int dx[4] = { 0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void func(int y, int x){
  visited[y][x] = true;
  queue<pair<int,int>> que;
  que.push({y,x});

  while(!que.empty()){
    int size = que.size();
    for(int i = 0; i < size;i++){
      int ay = que.front().first;
      int ax = que.front().second;
      que.pop();
      
      for(int j = 0; j < 4; j++){
        int tx = ax + dx[j];
        int ty = ay + dy[j];
        if(tx < 1 || tx > N || ty < 1 || ty > N) continue;
        if(visited[ty][tx] || arr[ty][tx] != arr[y][x]) continue;
        que.push({ty,tx});
        visited[ty][tx] = true;
      }
    }
  }
  
}

void solution(){
  int cnt = 0;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(visited[i][j]) continue;
      func(i,j);
      cnt++;
    }
  }
  cout << cnt << " ";
  for(int i = 1; i<=N;i++){
    for(int j = 1; j <= N; j++) {
      visited[i][j] = false;
      if(arr[i][j] == 'G') arr[i][j] = 'R';
    }
  }  
  
  cnt = 0;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(visited[i][j]) continue;
      func(i,j);
      cnt++;
    }
  }
  cout << cnt ;
  return;
}


int main(int argc, char** argv)
{
  input();
  solution();
   return 0;
}