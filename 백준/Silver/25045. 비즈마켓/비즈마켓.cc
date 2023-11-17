#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, M;
vector<int> arr;
vector<int> vec;
void input(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int num;
    cin >> num;
    arr.push_back(num);
  }
  for(int i = 0; i < M; i++){
    int num;
    cin >> num;
    vec.push_back(num);
  }
}

void solution(){
  sort(arr.rbegin(), arr.rend());
  sort(vec.begin(), vec.end());
  long long sum = 0;
  int size = min(arr.size(), vec.size());
  for(int i = 0; i < size; i++){
    if(arr[i] - vec[i] < 0) break;
    sum += arr[i] - vec[i];
  }
  cout << sum;
  
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