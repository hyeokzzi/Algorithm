#include<iostream>
#include<queue>
using namespace std;
int N, M, H;
int arr[101][101][101];

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, -1, 1};

typedef struct{
  int h;
  int y;
  int x;
}node;
queue<node> que;
int cnt_t;
void input(){
  cin >> M >> N >> H;
  for(int k =0; k < H; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        cin >> arr[k][i][j];
        if(arr[k][i][j] == 1) {
          que.push({k, i, j});
        }
        else if(arr[k][i][j] == 0)cnt_t++;
      }
    } 
  }
  return;
}

void solution(){
  int cnt = 0;
  if(que.empty()) {
    if(cnt_t > 0) cout << "-1";
    else cout << "0";
    return;
  }
  while(!que.empty()){
    int size = que.size();
    while(size--){
      node temp = que.front();
      que.pop();
      for(int i = 0; i < 6; i++){
        int tx = temp.x + dx[i];
        int ty = temp.y + dy[i];
        int th = temp.h + dh[i];
        if(tx < 0 || tx >= M || ty < 0 || ty >= N || th < 0 || th >= H) continue;
        if(arr[th][ty][tx] != 0) continue;
        arr[th][ty][tx] = 1;
        que.push({th, ty, tx});
      }
    }
    cnt++;
  }
  bool checked = false;
  for(int k =0; k < H; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(arr[k][i][j] == 0){
          checked = true;
        }
      }
      if(checked) break;
    }
    if(checked) break;
  }
  if(checked) cout << "-1";
  else cout << cnt - 1;
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