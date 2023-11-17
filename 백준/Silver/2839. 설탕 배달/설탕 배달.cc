#include<iostream>
using namespace std;
int N;

int main(int argc, char** argv)
{
  cin >> N;
  int M = N / 5;
  int K = N % 5;
  while(M > 0){
    if(K % 3 == 0) break;
    K += 5;
    M--;
  }
  if(K % 3 != 0){
    cout << "-1";
  }
  else{
    cout << M + K / 3;
  }
  
   return 0;
}