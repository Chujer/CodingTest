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

int N, M;
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, -1, 0, 1 };
vector<vector<int>> check(N, vector<int>(M, 0));

vector<vector<int>> arr(N, vector<int>(M, 0));
queue<pair<int, int>> que;

void BFS(int curX, int curY)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = curX + dirX[i];
		int nextY = curY + dirY[i];

		if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
			continue;

		if (arr[nextY][nextX] == 0)
			continue;

		if (check[nextY][nextX] != 0)
			continue;

		//if (check[nextY][nextX] == 0)
			check[nextY][nextX] = check[curY][curX] + 1;
		/*else
			check[nextY][nextX] = check[curY][curX] + 1 > check[nextY][nextX] ? check[nextY][nextX] : check[curY][curX] + 1;*/

		que.push({ nextX, nextY });
	}
	while (!que.empty())
	{
		pair<int, int> next = que.front();
		que.pop();
		BFS(next.first, next.second);
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	check.resize(N, vector<int>(M,0));
	arr.resize(N, vector<int>(M,0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	check[0][0] = 1;
	BFS(0, 0);
	cout << check[N - 1][M - 1];
}