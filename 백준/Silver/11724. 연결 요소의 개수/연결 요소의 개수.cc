#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> arr[1001];
bool visited[1001];

void input(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int st, en;
    cin >> st >> en;
    arr[st].push_back(en);
    arr[en].push_back(st);
  }
}
void func(int idx){
  visited[idx] = true;
  for(auto &e : arr[idx]){
    if(visited[e]) continue;
    func(e);
  }
}
void solution(){
  int cnt = 0;
  for(int i = 1; i <= N; i++){
    if(visited[i]) continue;
    func(i);
    cnt++;
  }
  cout << cnt;
}

int main(int argc, char** argv)
{
  input();
  solution();
   return 0;
}