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
//// �������� �Ǵ��ϴ� �Լ�
//int promising(int cdx) {
//
//	// ���� ���̸� �ȵǰ�, �밢���� �־�� �� �ȴ�.
//	for (int i = 0; i < cdx; i++) {
//		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//// nqueen �˰��� ����
//void nqueen(int cdx) {
//
//	// cdx�� ������ ����� �����ϰ� ������� ����, ã�� �Ϸ�
//	if (cdx == n) {
//		count++;
//		return;
//	}
//
//	for (int i = 0; i < n; i++) {
//		board[cdx] = i; // cdx��° ��, i��° ���� queen�� ���ƺ���.	
//		// ���� �� �࿡ �� �Ϳ� ���� �������� �Ǵ��Ѵ�.
//		if (promising(cdx)) { // �� �ڸ��� �ξ �����Ҵٸ�,
//			nqueen(cdx + 1); // �� ���� �࿡ ���� ���� ���� ���� �� ����.
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