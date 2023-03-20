# [Silver I] 구간 합 구하기 5 - 11660 

[문제 링크](https://www.acmicpc.net/problem/11660) 

### 성능 요약

메모리: 10228 KB, 시간: 600 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 문제 설명

<p>N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.</p>

<p>예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.</p>

<table class="table table-bordered" style="line-height:20.8px; width:158px">
	<tbody>
		<tr>
			<td style="text-align:center">1</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
		</tr>
		<tr>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
		</tr>
		<tr>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
			<td style="text-align:center">6</td>
		</tr>
		<tr>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
			<td style="text-align:center">6</td>
			<td style="text-align:center">7</td>
		</tr>
	</tbody>
</table>

<p>여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.</p>

<p>표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)</p>

### 출력 

 <p>총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.</p>



# 풀이과정

N의 최대 크기가 1024이기 때문에 최대 100만개의 원소를 가질 수 있는 2차원 배열에서 합을 구하는 것이다.   
시간제한이 있기 때문에 `하나씩 일일히 더하는 것`은 당연히 "정답이 아닐 것"이라고 생각했다.   

문제에서 나와있듯이 `두 점 좌표 사이에 위치한 값`들을 다 "더하는 것"이다.    
나는 이 문제를 `누적`을 통해 해결하고자 하였다.   

방법은 다음과 같다.
| 1. 배열의 한 행을 입력받을 때 이전 값들을 누적하며 저장한다.
| 2. 두 점 좌표를 이용하여 해당하지 않는 부분을 뺀다.   

그림으로 설명해보면   
![image](https://user-images.githubusercontent.com/87352996/226244064-8c400039-cc34-48af-90db-6b0b610ef59b.png)   
위의 사진대로 입력을 받았다고 하였을 때 저장을 아래 사진과 같이 변형해서 저장하였다.   

![image](https://user-images.githubusercontent.com/87352996/226244504-f8dc8d4c-d871-4080-9891-0a709578ecf2.png)   
위와 같이 같은 행을 기준으로 입력을 받을 때 `배열 값을 누적`하여 저장하였다.   

위 배열을 이용하여 두개의 x,y 좌표가 주어졌을 때 풀이 방식은 다음과 같다.   
![image](https://user-images.githubusercontent.com/87352996/226245128-e842a13c-3efe-4fc7-b534-966f747aea75.png)   

두 좌표 (2,3), (4,5)가 주어졌을 때(노란 영역) 영역의 "x좌표의 끝 수(18,22,26)"를 다 더한 후   
범위 "바로 앞에 숫자"(주황 영역)을 빼서 구하는 방법이다.   

그렇게 된다면 (18-2) + (22-1) + (26-2)의 식이 완성되고 결과로 61이 나오게 된다. 
