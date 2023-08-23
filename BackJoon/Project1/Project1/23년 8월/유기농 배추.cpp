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

queue<pair<int, int>> que;
int answer = 0;

void BFS(vector<vector<int>> arr, vector<vector<int>>& check, int x, int y, int count = 1)
{
	int left = x - 1;
	int right = x + 1;
	int top = y - 1;
	int bottom = y+ 1;
	//cout << "x : " << x << " " << "y : " << y << endl;

	if (check[y][x] == 0)
	{
		check[y][x] = 1;
	}

	if (left >= 0)
	{
		if (arr[y][left] != 0 && check[y][left] == 0)
		{
			check[y][left] = 1;
			que.push({ left, y });
		}
	}
	if (right < check[0].size())
	{
		if (arr[y][right] != 0 && check[y][right] == 0)
		{
			check[y][right] = 1;
			que.push({ right, y });
		}
	}
	if (top >= 0)
	{
		if (arr[top][x] != 0 && check[top][x] == 0)
		{
			check[top][x] = 1;
			que.push({ x, top });
		}
	}
	if (bottom < arr.size())
	{
		if (arr[bottom][x] != 0 && check[bottom][x] == 0)
		{
			check[bottom][x] = 1;
			que.push({ x, bottom });
		}
	}

	while (!que.empty())
	{
		int tempX = que.front().first, tempY = que.front().second;
		que.pop();
		BFS(arr, check, tempX, tempY, 0);

	}
	answer += count;
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M, K;

	cin >> T;
	
	for (int r = 0; r < T; r++)
	{
		cin >> M >> N >> K;

		vector<vector<int>> arr(N, vector<int>(M, 0));
		vector<vector<int>> check(arr.size(), vector<int>(arr[0].size(), 0));
		vector<pair<int, int>> pos;

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
			pos.push_back({ x, y });
		}
	
		for (pair<int, int> p : pos)
		{
			if (check[p.second][p.first] == 0)
			{
			//	cout << "Search ===================================" << endl;
				BFS(arr, check, p.first, p.second);
			}
		}

		cout << answer << "\n";

		answer = 0;
	}



}