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
int dirX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dirY[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

pair<int, int> goal;
vector<vector<int>> board;
vector<vector<int>> check;
queue<pair<int, int>> que;
int answer;
pair<int, int> temp; 
int posX, posY;

void BFS(pair<int,int> start, int count)
{

	if (start == goal)
	{
		answer = check[goal.second][goal.first]-1;
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		posX = start.first + dirX[i];
		posY = start.second + dirY[i];

		if (posX < 0 || posY < 0 || posX >= board.size() || posY >= board.size())
			continue;

		if (check[posY][posX] != 0)
			continue;

		check[posY][posX] = check[start.second][start.first] + 1;
		que.push({ posX, posY });

	}


	if (!que.empty())
	{
		temp = que.front();
		que.pop();

		BFS(temp, count);
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		pair<int, int> start;
		cin >> M;
		answer = M * M;

		board.resize(M, vector<int>(M, 0));
		check.resize(M, vector<int>(M, 0));

		int temp1, temp2;
		cin >> temp1 >> temp2;
		start = { temp1, temp2 };

		cin >> temp1 >> temp2;
		goal = { temp1, temp2 };

		check[start.second][start.first] = 1;
		BFS(start, 0);
		cout << answer << "\n";
		check.clear();
		board.clear();
		while (!que.empty())
			que.pop();
	}
}