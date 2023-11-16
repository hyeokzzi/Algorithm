#include<iostream>
#include<queue>
using namespace std;
int dx[7] = {0, 1, 1, 1, -1, -1, -1};
int dy[7] = {-1, -1, 0, 1, 1, 0, -1};
bool visited[2001][2001];
char arr[2001][2001];
int N,start_x,start_y;
void input(){
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j<N ;j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'F'){
        start_x = j;
        start_y = i;
      }
    }
  }
}

void solution(){
  queue<pair<int,int>> que;
  que.push({start_y, start_x});
  visited[start_y][start_x] = true; 
  int cnt = 0;
  while(!que.empty()){
    int size = que.size();
    for(int k = 0; k < size; k++){
      int ay = que.front().first;
      int ax = que.front().second;
      que.pop();
      
      for(int i = 0; i < 7; i++){
        int tx = ax + dx[i];
        int ty = ay + dy[i];
        if(tx < 0 || tx > N-1 || ty < 0 || ty > N-1) continue;
        if(visited[ty][tx] || arr[ty][tx] == '#') continue;
        que.push({ty,tx});
        visited[ty][tx] = true;
        cnt++;
      }
    }
  }
  cout << cnt;
  
}

int main(int argc, char** argv)
{
  input();
  solution();

   return 0;
}