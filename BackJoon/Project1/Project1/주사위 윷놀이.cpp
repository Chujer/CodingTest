#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <queue>

using namespace std;

vector<vector<int>> board =
{
	{0,2,4,6,8,10, 12,14,16,18,20 ,22,24,26,28,30 ,32,34,36,38,40},
	{10,13,16,19, 25, 30, 35,40},
	{20,22,24, 25, 30,35,40},
	{30 ,28,27,26, 25, 30,35,40}
};

map<pair<int, int>, bool> check;

int answer = 0;
vector<vector<int>> ppp(4, vector<int>(3, 0));

void DFS(vector<int> commend, int count, int score)
{
	if (count == 10)
	{
		if (score == 193)
			int a = 0;
		answer = max(answer, score);
		return;
	}
	for (int i = 0; i < ppp.size(); i++)
	{
		if (ppp[i][2] == 1)
			continue;

		int x = ppp[i][0] + commend[count];
		int y = ppp[i][1];
		pair<int, int> ori = { ppp[i][0], ppp[i][1] };

		if (x >= board[y].size())
		{
			ppp[i][2] = 1;
			check[ori] = false;
			DFS(commend, count + 1, score);
			check[ori] = true;
			ppp[i][2] = 0;
			continue;
		}

		if (check[{x, y}] == true)
			continue;

		if (y == 0)
		{
			switch (board[y][x])
			{
			case 10:
				y = 1;
				x = 0;
				break;
			case 20:
				y = 2;
				x = 0;
				break;
			case 30:
				y = 3;
				x = 0;
			default:
				break;
			}
		}

		score += board[y][x];
		ppp[i][0] = x;
		ppp[i][1] = y;
		check[ori] = false;
		check[{x, y}] = true;

		DFS(commend, count + 1, score);
		score -= board[y][x];

		check[{x, y}] = false;
		check[ori] = true;
		ppp[i][0] = ori.first;
		ppp[i][1] = ori.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int plusCount = 0;

	vector<int> commend(10);
	for (int i = 0; i < 10; i++)
		cin >> commend[i];

	DFS(commend, 0, 0);
	int a = answer;
}