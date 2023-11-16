#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> arr;
int N, M;
void input(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int n;
    cin >> n;
    arr.push(n);
  }
}
void solution(){
  vector<int> vec;
  for(int i = 0; i < M; i++){
    vec.push_back(arr.front());
    arr.pop();
  }
  for(int i = 0; i < N - M + 1; i++){
    int n;
    cin >> n;
    sort(vec.begin(), vec.end());
    vec.erase(vec.begin() + (n - 1));
    if(arr.empty()) break;
    vec.push_back(arr.front());
    arr.pop();
  }
  sort(vec.begin(), vec.end());
  for(auto &e : vec){
    cout << e << " ";
  }
}

int main(int argc, char** argv)
{
  input();
  solution();
   return 0;
}