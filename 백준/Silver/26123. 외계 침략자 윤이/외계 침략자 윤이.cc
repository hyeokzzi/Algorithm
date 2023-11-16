#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
int N, M;
void input(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int num;
    cin >> num;
    arr.push_back(num);
  }
}

void solution(){
  sort(arr.rbegin(), arr.rend());
  int cnt = 0;
  int idx = 0;
  int t = arr.front() - M;
  long long sum = 0;
  if(t < 0){
    for(int i = 0; i < N; i++) sum+= arr[i];
  }
  else{
    for(int i = 0; i < N; i++){
      if( arr[i] <= t) break;
      sum += (arr[i]- t);
    }
  }
  cout << sum;
}

int main(int argc, char** argv)
{
  input();
  solution();
   return 0;
}