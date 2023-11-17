#include<iostream>
#include<queue>
using namespace std;
int parking[101];
int car[2001]; // 차 무게
int cost[101]; // 공간 비용
int N, M;
queue<int> que;
void input(){
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    cin >> cost[i];
  }
  for(int i = 1; i <= M; i++){
    cin >> car[i];
  }
}

void solution(){
  int total_cost = 0;
  for(int i = 0; i < M * 2; i++){
    int num;
    cin >> num;
    // 입차
    if(num > 0){
      int idx = 1;
      while(idx <= N && parking[idx] != 0) idx++;
      if(idx > N) que.push(num);
      else{
        parking[idx] = num;
      }
    }
    // 출차
    else{
      int car_num = num * -1;
      for(int i = 1; i <= N; i++){
        if(parking[i] == car_num){
          // 정산
          total_cost += (car[car_num] * cost[i]); 
          // 채우기
          if(!que.empty()){
            parking[i] = que.front();
            que.pop();
          }
          else parking[i] = 0;
          break;
        }
      }
    }
  }
  cout << total_cost;
}


int main(int argc, char** argv)
{
  input();
  solution();
   return 0;
}