#include<iostream>
using namespace std;
int arr[6];
int main(int argc, char** argv)
{
  for(int i = 1; i <=5 ; i++){
    cin >> arr[i];
  }
  int sum = 0;
  sum += arr[5];
  // 4 처리
  while(arr[4] > 0 && arr[1] > 0){
    arr[1]--;
    arr[4]--;
    sum++;
  }
  while(arr[4]-- > 0) sum++;

  // 3 처리 3 2  3 1 1
  while(arr[3] > 0 && arr[2] > 0){
    arr[3]--;
    arr[2]--;
    sum++;
  }
  while(arr[3] > 0 && arr[1] > 1){
    arr[3]--;
    arr[1]-=2;
    sum++;
  }
  while(arr[3] > 0 && arr[1] > 0){
    arr[3]--;
    arr[1]--;
    sum++;
  }
  while(arr[3]-- > 0 ) sum++;

  // 2 2 1
  while(arr[2] > 1 && arr[1] > 0){
    arr[2] -= 2;
    arr[1]--;
    sum++;
  }
  // 2 1 1 1
  while(arr[2] > 0 && arr[1] > 2){
    arr[2]--;
    arr[1] -= 3;
    sum++;
  }
  // 2 1 1
  while(arr[2] > 0 && arr[1] > 1){
    arr[2]--;
    arr[1] -= 2;
    sum++;
  }
  // 2 2
  while(arr[2] > 1){
    arr[2] -= 2;
    sum++;
  }
  // 2 1
  while(arr[2] > 0 && arr[1] > 0){
    arr[2]--;
    arr[1]--;
    sum++;
  }
  // 2
  while(arr[2] > 0){
    arr[2]--;
    sum++;
  }
  if(arr[1] % 5  == 0) sum += arr[1] / 5;
  else sum += ((arr[1] / 5) + 1);
  cout << sum;
   return 0;
}