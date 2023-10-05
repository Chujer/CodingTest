#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <queue>

using namespace std;
int aanswer = 0;

void DFS(vector<int> check, int answer, int index, int count,vector<pair<int,int>> in)
{
	if (check[index] != 100)
		return;
	count++;
	check[index] = count;
	in.push_back({ index, count });

	for (int i = 0; i < in.size()-1; i++)
	{
		if (index != in[i].first)
		{
			if (abs(check[index] - in[i].second) == abs(in[i].first - index))
				return;
		}
	}
	answer++;
	if (answer == check.size())
		aanswer++;
	for (int i = 0; i < check.size(); i++)
	{
		DFS(check, answer, i, count,in);
	}
}

int main()
{
	int N;
	cin >> N;
	
	vector<int> check;
	vector<pair<int,int>> in;

	check.resize(N, 100);
	int answer = 0;

	for (int i = 0; i < check.size(); i++)
	{
		DFS(check, answer, i, 0,in);
	}
	
	cout << aanswer;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int count = 0;
//int n;
//int board[15];
//
//// 유망한지 판단하는 함수
//int promising(int cdx) {
//
//	// 같은 열이면 안되고, 대각선상에 있어서도 안 된다.
//	for (int i = 0; i < cdx; i++) {
//		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//// nqueen 알고리즘 수행
//void nqueen(int cdx) {
//
//	// cdx가 마지막 행까지 수행하고 여기까지 오면, 찾기 완료
//	if (cdx == n) {
//		count++;
//		return;
//	}
//
//	for (int i = 0; i < n; i++) {
//		board[cdx] = i; // cdx번째 행, i번째 열에 queen을 놓아본다.	
//		// 이후 그 행에 둔 것에 대한 유망성을 판단한다.
//		if (promising(cdx)) { // 그 자리에 두어도 괜찮았다면,
//			nqueen(cdx + 1); // 그 다음 행에 대해 퀸을 놓는 것을 해 본다.
//		}
//	}
//}
//
//int main() {
//
//	
//	scanf_s("%d", &n);
//	nqueen(0);
//	printf("%d", count);
//
//}