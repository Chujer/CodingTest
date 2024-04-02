#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> check;
vector<vector<int>> DP;
queue<pair<int, int>> que;

int dirX[4] = { -1,1,0,0 };
int dirY[4] = { 0,0,-1,1 };

void DFS(int x, int y)
{
	
	for (int i = 0; i < 4; i++)
	{
		int curX = x + dirX[i];
		int curY = y + dirY[i];


		if (curX < 0 || curY < 0 || curX >= board[0].size() || curY >= board.size())
			continue;
		if (board[curY][curX] >= board[y][x] || check[curY][curX] == true)
			continue;

		que.push({ curX, curY });
		DP[curY][curX] ++;
		check[curY][curX] = true;;
	}

	while (!que.empty())
	{
		int tempX = que.front().first;
		int tempY = que.front().second;
		que.pop();
		DFS(tempX, tempY);
		check[tempY][tempX] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> y >> x;
	check.resize(y, vector<bool>(x, false));
	DP.resize(y, vector<int>(x, false));
	board.resize(y, vector<int>(x, false));

	check[0][0] = true;
	DP[0][0] = 1;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> board[i][j];
		}
	}
	DFS(0, 0);

	cout << DP[y - 1][x - 1];
}