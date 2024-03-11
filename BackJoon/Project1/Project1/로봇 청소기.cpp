#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <queue>

using namespace std;

enum DIR{N = 0, E, S, W};
int dirPosX[4] = { 0,1, 0, -1};
int dirPosY[4] = { -1,0,1, 0 };
DIR dir;
int clearCount = 0;
int startZeroCount = 0;

void Check(vector<int>& curPos, vector<vector<int>>& boards)
{
	int nextDir = 360 + dir * 90;
	nextDir -= 90;
	dir = (DIR)(((nextDir / 90) % 360)%4);
	int iDir = dir;

	int nextPosX = curPos[0] + dirPosX[dir];
	int nextPosY = curPos[1] +dirPosY[dir];

	if (nextPosX < 0 || nextPosX >= boards[0].size() || nextPosY < 0 || nextPosY >= boards.size())
		Check(curPos, boards);
	else if(boards[nextPosY][nextPosX] == 1)
	{ }
	else if(boards[nextPosY][nextPosX] == 0)
	{
		curPos[0] = nextPosX;
		curPos[1] = nextPosY;
	}
}

bool CheckMoveBack(vector<int>& curPos, vector<vector<int>>& boards)
{
	int nextPosX = curPos[0];
	int nextPosY = curPos[1];
	switch (dir)
	{
	case N:
		nextPosY++;
		break;
	case E:
		nextPosX--;
		break;
	case S:
		nextPosY--;
		break;
	case W:
		nextPosX++;
		break;
	default:
		break;
	}

	if (nextPosX < 0 || nextPosX >= boards[0].size() || nextPosY < 0 || nextPosY >= boards.size())
		return false;
	else if (boards[nextPosY][nextPosX] == 1)
		return false;
	else
	{
		curPos[0] = nextPosX;
		curPos[1] = nextPosY;
	}
	return true;
}
void Clean(vector<vector<int>>& boards, vector<int>& curPos)
{
	int curX = curPos[0], curY = curPos[1];

	if (boards[curY][curX] == 0)
	{
		boards[curY][curX] = 2; 
		clearCount++;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextPosX = curPos[0] + dirPosX[i];
		int nextPosY = curPos[1] + dirPosY[i];

		if (nextPosX < 0 || nextPosX >= boards[0].size() || nextPosY < 0 || nextPosY >= boards.size())
			continue;
		else if (boards[nextPosY][nextPosX] == 1)
			continue;
		if (boards[nextPosY][nextPosX] == 0)
		{
			Check(curPos, boards);
			Clean(boards, curPos);
		}
	}

	if (CheckMoveBack(curPos, boards))
	{
		Clean(boards, curPos);
	}
	else
	{
		return;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	int tempdir;
	vector<int> pos(2);
	cin >> y >> x; 
	vector<vector<int>> boards(y, vector<int>(x));
	cin >> pos[1] >> pos[0]  >> tempdir;		//1 = y 0 = x
	dir = (DIR)tempdir;

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> boards[i][j];
		}
	}

	Clean(boards, pos);

	cout << clearCount;
}