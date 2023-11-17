#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
vector<int> arr;

int N;
void input(){
  cin >> N;
  for(int i = 0; i < N ;i++){
    int t;
    cin >> t;
    arr.push_back(t);
  }
}

void solution(){
  sort(arr.begin(), arr.end());
  int sum_s = 0, sum_b = 0;
  for(int i = 0; i < N / 2; i++) sum_s += arr[i];
  for(int i = N / 2; i < N; i++) sum_b += arr[i];
  cout << sum_s << " " << sum_b;
}


int main(int argc, char** argv)
{
  input();
  solution();
   return 0;
}