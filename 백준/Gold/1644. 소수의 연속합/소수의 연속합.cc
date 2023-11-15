#include<iostream>
#include<vector>
using namespace std;
int N, arr[4000001];
vector<int> vec;
int main(int argc, char** argv)
{
  cin >> N;
  for(int i = 2; i<= N; i++){
    arr[i] = i;
  }
  for(int i = 2; i <= N; i++){
    if(arr[i] == i){
      vec.push_back(i);
      for(int j = i*2; j<= N; j += i) arr[j] = 0;
    }
  }

  int st = 0, en = 1, cnt = 0;
  if(vec.empty()) {
    cout << "0";
    return 0;
  }
  int sum = vec[st];
  int size = vec.size();
  while(st < size){
    while(en < size && sum + vec[en] <= N){
      sum += vec[en];
      en++;
    }
    if(sum == N) cnt++;
    sum -= vec[st];
    st++;
  }
  cout << cnt;
   return 0;
}