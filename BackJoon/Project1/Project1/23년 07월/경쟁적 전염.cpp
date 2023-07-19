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

void Multiplication(vector<vector<int>>& arr, vector<vector<int>> pos, int name, map<int, vector<vector<int>>>& virus)
{
	vector<vector<int>> temp;
	for (vector<int> p : pos)
	{
		int x = p[1];
		int y = p[0];
		int left = p[1] - 1;
		int right = p[1] + 1;
		int top = p[0] - 1;
		int bottom = p[0] + 1;
			
		if (left >= 0)
		{
			if (arr[y][left] == 0)
			{
				arr[y][left] = name;
				virus[name].push_back({ y,left });
				temp.push_back({ y,left });
			}
		}
		if (right < arr[0].size())
		{
			if (arr[y][right] == 0)
			{
				arr[y][right] = name;
				virus[name].push_back({ y,right });
				temp.push_back({ y,right });
			}
		}
		if (top >= 0)
		{
			if (arr[top][x] == 0)
			{
				arr[top][x] = name;
				virus[name].push_back({ top,x });
				temp.push_back({ top,x });
			}
		}
		if (bottom < arr.size())
		{
			if (arr[bottom][x] == 0)
			{
				arr[bottom][x] = name;
				virus[name].push_back({ bottom,x });
				temp.push_back({ bottom,x });
			}
		}
	}

	virus[name] = temp;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	map<int, vector<vector<int>>> virus;
	vector<vector< int>> arr;

	for (int i = 0; i < N; i++)
	{
		vector<int> temparr;
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			temparr.push_back(temp);
			if (temparr[j] != 0)
				virus[temparr[j]].push_back({ i,j });
		}
		arr.push_back(temparr);
	}

	int S, X, Y;
	cin >> S >> X >> Y;

	for (int i = 0; i < S; i++)
	{
		for (pair<int, vector<vector<int>>> v : virus)
		{
			Multiplication(arr, virus[v.first], v.first, virus);
		}
	}
	X -= 1;
	Y -= 1;
	cout << arr[X][Y];
}