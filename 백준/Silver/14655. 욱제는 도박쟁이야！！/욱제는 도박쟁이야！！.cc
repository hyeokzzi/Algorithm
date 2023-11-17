#include<iostream>
#include<cmath>

using namespace std;
int N;
int main(int argc, char** argv)
{
  int sum = 0;
  cin >> N;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < N; j++){
      int num;
      cin >> num;
      sum += abs(num);
    }
  }
  cout << sum;
   return 0;
}