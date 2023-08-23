#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> datas(N+1,vector<int>(N+1,0));
	int prevNum = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> datas[i][j];
			datas[i][j] += prevNum;
			prevNum = datas[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int startX, startY;
		int endX, endY;
		bool minusX = true;
		int sum = 0;
		cin >> startY >> startX >>  endY >> endX;

		if (startX == 1)
			minusX = false;
		
		for (int j = startY; j <= endY; j++)
		{
			if (startX > 1)
				sum += datas[j][endX] - datas[j][startX-1];
			else
				sum += datas[j][endX] - datas[j-1][N];
		}
		cout << sum << "\n";
	}
}