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
int minRange;
int maxRange;

void BFS(vector<vector<int>> arr, pair<int,int> pos, queue<pair<int,int>>& que,  vector<vector<bool>>& vist, vector<pair<int, int>>& sumPos)
{
	if(!que.empty())
		que.pop();
	int left = pos.second - 1;
	int right = pos.second + 1;
	int top = pos.first - 1;
	int bottom = pos.first + 1;
	sumPos.push_back(pos);

	if (left >= 0)
	{
		int sub = abs(arr[pos.first][pos.second] - arr[pos.first][left]);
		if (sub >= minRange && sub <= maxRange)
		{
			if (vist[pos.first][left] == false)
			{
				vist[pos.first][left] = true;
				que.push(make_pair(pos.first, left));
			}
		}
	}
	if (right < arr.size())
	{
		int sub = abs(arr[pos.first][pos.second] - arr[pos.first][right]);
		if (sub >= minRange && sub <= maxRange)
		{
			if (vist[pos.first][right] == false)
			{
				vist[pos.first][right] = true;
				que.push(make_pair(pos.first, right));
			}
		}
	}
	if (top >= 0)
	{
		int sub = abs(arr[pos.first][pos.second] - arr[top][pos.second]);
		if (sub >= minRange && sub <= maxRange)
		{
			if (vist[top][pos.second] == false)
			{
				vist[top][pos.second] = true;
				que.push(make_pair(top, pos.second));
			}
		}
	}
	if (bottom < arr.size())
	{
		int sub = abs(arr[pos.first][pos.second] - arr[bottom][pos.second]);
		if (sub >= minRange && sub <= maxRange)
		{
			if (vist[bottom][pos.second] == false)
			{
				vist[bottom][pos.second] = true;
				que.push(make_pair(bottom, pos.second));
			}
		}
	}

	if (!que.empty())
	{
		BFS(arr, que.front(), que, vist, sumPos);
	}
	else
	{
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N >> minRange >> maxRange;

	vector<vector<int>> words(N, vector<int>(N));
	vector<vector<bool>> visitArr(N, vector<bool>(N,false));
	queue<pair<int, int>> que;
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> words[i][j];
		}
	}

	cout << "==================================\n";
	vector<pair<int, int>> sumPos;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visitArr[i][j] == false)
			{
				BFS(words, make_pair(i, j), que, visitArr, sumPos);
			}
		}
		cout << "\n";
	}
	int sum = 0;
	for (pair<int, int> p : sumPos)
	{
		sum += words[p.first][p.second];
	}
	for (pair<int, int> p : sumPos)
	{
		words[p.first][p.second] = sum / sumPos.size();
	}

	cout << "==================================\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << words[i][j] << " ";
		}
		cout << "\n";
	}

}